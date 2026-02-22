#pragma once

#include <cassert>
#include <memory>
#include <utility>

#include "error.h"
#include "list.h"
#include "vector.h"

namespace cool {

template <class T, typename Container = cool::vector<T>>
class stack {
 public:
  using size_type = size_t;

  void push(const T& elem) { m_container.push_back(elem); }
  void pop() { m_container.pop_back(); }

  T& top() {
    ASSERT(!empty(), "cool::stack::top(): stack is empty");
    return m_container.back();
  }
  const T& top() const {
    ASSERT(!empty(), "cool::stack::top(): stack is empty");
    return m_container.back();
  }

  size_type size() const { return m_container.size(); }
  bool empty() const { return m_container.empty(); }

 private:
  Container m_container;
};

}  // namespace cool