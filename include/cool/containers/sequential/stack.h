#pragma once

#include <memory>
#include <utility>

namespace cool {

template <class T>
class stack {
 public:
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  stack() = default;
  ~stack() { destroy(); }
  stack(const stack& v) { initialize_copy(m_data, m_end); }
  stack(stack&& v) noexcept { initialize_move(m_data, m_end); }

  stack& operator=(const stack& v);
  stack& operator=(stack&& v) noexcept;

  size_type size() const { return m_current - m_data; }
  bool empty() const { return size() == ptrdiff_t(0); }

  void push(const T& elem) {
    if (m_current == m_end) {
      resize();
    }
    std::construct_at(m_current++, elem);
  }

  T top() const { return *(m_current - 1); }

 private:
  void resize();
  void destroy();

  void initialize_copy(const_iterator left, const_iterator right);
  void initialize_move(const_iterator left, const_iterator right);

  iterator m_data = nullptr;
  iterator m_end = nullptr;
  iterator m_current = nullptr;
  std::allocator<T> m_allocator = std::allocator<T>();
};

template <class T>
stack<T>& stack<T>::operator=(const stack<T>& v) {
  if (&v != this) {
    destroy();
    initialize_copy(v.begin(), v.end());
  }
  return *this;
}

template <class T>
stack<T>& stack<T>::operator=(stack<T>&& v) noexcept {
  if (&v != this) {
    destroy();
    initialize_move(v.begin(), v.end());
  }
  return *this;
}

template <class T>
void stack<T>::destroy() {
  if (m_data) {
    std::destroy(m_data, m_current);
    m_allocator.deallocate(m_data, m_current - m_data);
  }
  m_data = m_end = m_current = nullptr;
}

template <class T>
void stack<T>::resize() {
  size_type old_size = size();
  size_type new_capacity = old_size == 0 ? 1 : 2 * old_size;

  iterator new_data = m_allocator.allocate(new_capacity);
  std::uninitialized_move(m_data, m_current, new_data);

  if (m_data) {
    std::destroy(m_data, m_current);
    m_allocator.deallocate(m_data, m_end - m_data);
  }

  m_data = new_data;
  m_current = m_data + old_size;
  m_end = m_data + new_capacity;
}

template <class T>
void stack<T>::initialize_copy(const_iterator left, const_iterator right) {
  m_data = m_allocator.allocate(right - left);
  m_current = m_end = std::uninitialized_copy(left, right, m_data);
}

template <class T>
void stack<T>::initialize_move(const_iterator left, const_iterator right) {
  m_data = m_allocator.allocate(right - left);
  m_current = m_end = std::uninitialized_move(left, right, m_data);
}

}  // namespace cool