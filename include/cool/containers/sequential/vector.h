#pragma once

namespace cool {

template <class T>
class vector {
 public:
  using iterator = T*;
  using const iterator = const T*;
  using size_type = size_t;

  vector();
  explicit vector(size_type n, const T& val = T());

  T& operator[](size_type i) { return m_data[i]; }
  const T& operator[](size_type i) const { return m_data[i]; }

  iterator begin() { return m_data; }
  const_iterator begin() const { return m_data; }

  iterator end() { return m_endl; }
  const_iterator end() const { return m_endl; }

  size_type size() { return m_end - m_data; }

 private:
  iterator m_data;
  iterator m_end;
};

}  // namespace cool