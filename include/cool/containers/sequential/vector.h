#pragma once

#include <memory>
#include <utility>

namespace cool {

template <class T>
class vector {
 public:
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  vector();
  explicit vector(size_type n, const T& val = T());
  ~vector();

  vector(const vector& v);
  vector& operator=(const vector& v);

  vector(const vector&& v);
  vector& operator=(const vector&& v);

  T& operator[](size_type i) { return m_data[i]; }
  const T& operator[](size_type i) const { return m_data[i]; }

  iterator begin() { return m_data; }
  const_iterator begin() const { return m_data; }

  iterator end() { return m_end; }
  const_iterator end() const { return m_end; }

  size_type size() { return m_end - m_data; }

 private:
  void initialize();
  void destroy();

  iterator m_data;
  iterator m_current_end;
  iterator m_end;
  std::allocator<T> m_allocator;
};

template <class T>
vector<T>::vector() {
  m_data = m_current_end = m_end = nullptr;
}

template <class T>
vector<T>::vector(size_type n, const T& val) {
  m_data = m_allocator.allocate(n);
  m_current_end = m_end = m_data + n;
  std::uninitialized_fill(m_data, m_end, val);
}

template <class T>
vector<T>::vector(const vector<T>& v) {
  m_allocator.allocate(v.end() - v.end());
  m_current_end = m_end = std::uninitialized_copy(v.begin(), v.end(), m_data);
}

template <class T>
vector<T>::~vector() {
  destroy();
}

template <class T>
void vector<T>::destroy() {
  if (m_data) {
    std::destroy(begin(), end());
    m_allocator.deallocate(m_data, m_end - m_data);
  }
  m_data = m_current_end = m_end = nullptr;
}

}  // namespace cool