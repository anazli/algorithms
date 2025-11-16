#pragma once

#include <memory>
#include <utility>

/*************************************************************
 *                    Dynamic Array
 * -----------------------------------------------------------
 * A simple dynamic array implementation in a similar style as
 * stl's vector.
 **************************************************************/

namespace cool {

template <class T, class Allocator = std::allocator<T>>
class vector {
 public:
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  vector();
  vector(const Allocator& alloc);
  explicit vector(size_type n, const T& val = T());
  vector(const vector& v);
  vector(vector&& v) noexcept;
  ~vector();

  vector& operator=(const vector& v);
  vector& operator=(vector&& v) noexcept;

  T& operator[](size_type i) { return m_data[i]; }
  const T& operator[](size_type i) const { return m_data[i]; }

  iterator begin() { return m_data; }
  const_iterator begin() const { return m_data; }

  iterator end() { return m_end; }
  const_iterator end() const { return m_end; }

  size_type size() const { return m_current_end - m_data; }
  void push_back(const T& elem) {
    if (m_current_end == m_end) {
      resize();
    }
    std::construct_at(m_current_end++, elem);
  }
  bool empty() const { return size() == ptrdiff_t(0); }

 private:
  void initialize_copy(const_iterator left, const_iterator right);
  void initialize_move(const_iterator left, const_iterator right);
  void destroy();
  void resize();

  iterator m_data;
  iterator m_current_end;
  iterator m_end;
  Allocator m_allocator;
};

template <class T, class Allocator>
vector<T, Allocator>::vector()
    : m_data(nullptr), m_current_end(nullptr), m_end(nullptr), m_allocator() {}

template <class T, class Allocator>
vector<T, Allocator>::vector(const Allocator& alloc)
    : m_data(nullptr),
      m_current_end(nullptr),
      m_end(nullptr),
      m_allocator(alloc) {}

template <class T, class Allocator>
vector<T, Allocator>::vector(size_type n, const T& val) : m_allocator() {
  m_data = m_allocator.allocate(n);
  m_current_end = m_end = m_data + n;
  std::uninitialized_fill(m_data, m_end, val);
}

template <class T, class Allocator>
vector<T, Allocator>::vector(const vector<T, Allocator>& v) : m_allocator() {
  initialize_copy(v.begin(), v.end());
}

template <class T, class Allocator>
vector<T, Allocator>::vector(vector<T, Allocator>&& v) noexcept
    : m_allocator(v.m_allocator) {
  initialize_move(v.begin(), v.end());
}

template <class T, class Allocator>
vector<T, Allocator>::~vector() {
  destroy();
}

template <class T, class Allocator>
vector<T, Allocator>& vector<T, Allocator>::operator=(
    const vector<T, Allocator>& v) {
  if (&v != this) {
    destroy();
    initialize_copy(v.begin(), v.end());
  }
  return *this;
}

template <class T, class Allocator>
vector<T, Allocator>& vector<T, Allocator>::operator=(
    vector<T, Allocator>&& v) noexcept {
  if (&v != this) {
    destroy();
    initialize_move(v.begin(), v.end());
  }
  return *this;
}

template <class T, class Allocator>
void vector<T, Allocator>::destroy() {
  if (m_data) {
    std::destroy(begin(), end());
    m_allocator.deallocate(m_data, m_end - m_data);
  }
  m_data = m_current_end = m_end = nullptr;
}

template <class T, class Allocator>
void vector<T, Allocator>::initialize_copy(const_iterator left,
                                           const_iterator right) {
  m_data = m_allocator.allocate(right - left);
  m_current_end = m_end = std::uninitialized_copy(left, right, m_data);
}

template <class T, class Allocator>
void vector<T, Allocator>::initialize_move(const_iterator left,
                                           const_iterator right) {
  m_data = m_allocator.allocate(right - left);
  m_current_end = m_end = std::uninitialized_move(left, right, m_data);
}

template <class T, class Allocator>
void vector<T, Allocator>::resize() {
  size_type size = 2 * (m_end - m_data);
  iterator data = m_allocator.allocate(size);
  iterator current_end = std::uninitialized_copy(m_data, m_current_end, data);
  destroy();
  m_data = data;
  m_current_end = current_end;
  m_end = m_data + size;
}

}  // namespace cool