#pragma once

#include <memory>
#include <utility>

/*************************************************************
 *                    Linked List
 * -----------------------------------------------------------
 * A simplified version of stl list.
 **************************************************************/

namespace cool {

template <class T>
class Node {
 public:
  using node_ptr = Node<T>*;
  explicit Node(const T& data)
      : m_data(data), m_prev(nullptr), m_next(nullptr) {}
  Node(const T& data, node_ptr prev, node_ptr next)
      : m_data(data), m_prev(prev), m_next(next) {}

  void set_data(const T& data) { m_data = data; }
  void set_prev(node_ptr prev) { m_prev = prev; }
  void set_next(node_ptr next) { m_next = next; }

  T& get_data() const { return m_data; }
  const node_ptr prev() const { return m_prev; }
  const node_ptr next() const { return m_next; }

 private:
  T m_data;
  node_ptr m_prev;
  node_ptr m_next;
};

template <class T, class Allocator = std::allocator<T>>
class list {
 public:
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

 private:
  iterator m_head;
  iterator m_tail;
};

}  // namespace cool