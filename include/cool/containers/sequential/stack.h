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

  ~stack() { destroy(); }

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

  iterator m_data = nullptr;
  iterator m_end = nullptr;
  iterator m_current = nullptr;
  std::allocator<T> m_allocator = std::allocator<T>();
};

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
  size_type s = std::max(2 * (m_end - m_data), ptrdiff_t(1));
  iterator data = m_allocator.allocate(s);
  iterator current_end = std::uninitialized_copy(m_data, m_current, data);
  destroy();
  m_data = data;
  m_current = current_end;
  m_end = m_data + s;
}

}  // namespace cool