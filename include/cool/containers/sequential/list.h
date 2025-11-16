#pragma once

#include <memory>
#include <utility>

/*************************************************************
 *                    Linked List
 * -----------------------------------------------------------
 * A simplified version of stl list.
 **************************************************************/

namespace cool {

template <class T, class Allocator = std::allocator<T>>
class list {
 public:
  using iterator = Node<T>*;
  using const_iterator = const Node<T>*;
  using size_type = size_t;

 private:
  iterator m_head = nullptr;
  iterator m_tail = nullptr;
  size_type m_size = 0;
  Allocator m_allocator = std::allocator<T>();

  template <class T>
  class Node {
   public:
    using node_ptr = Node<T>*;
    explicit Node(const T& data)
        : m_data(data), m_prev(nullptr), m_next(nullptr) {}
    Node(const T& data, node_ptr prev, node_ptr next)
        : m_data(data), m_prev(prev), m_next(next) {}

    T m_data;
    node_ptr m_prev;
    node_ptr m_next;
  };
};

}  // namespace cool