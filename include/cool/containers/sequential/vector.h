#pragma once

#include <memory>

namespace cool {

template <class T>
class vector {
 public:
  using iterator = std::unique_ptr<T*>;
  using const iterator = const std::unique_ptr<T*>;
  using size_type = size_t;

  vector();
  vector(size_type n, const T& val = T());

  T& operator[](size_type i) { return m_data[i]; }
  const T& operator[](size_type i) const { return m_data[i]; }

  size_type size() { return m_end - m_data; }

 private:
  iterator m_data;
  iterator m_end;
};

}  // namespace cool