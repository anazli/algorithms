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

  ~stack();

  size_type size() const { return m_current - m_data; }
  bool empty() const { return size() == ptrdiff_t(0); }

 private:
  iterator m_data = nullptr;
  iterator m_end = nullptr;
  iterator m_current = nullptr;
  std::allocator<T> m_allocator = std::allocator<T>();
};

template <class T>
stack<T>::~stack() {
  if (m_data) {
    std::destroy(m_data, m_end);
    m_allocator.deallocate(m_data, m_end - m_data);
  }
  m_data = m_end = m_current = nullptr;
}

}  // namespace cool