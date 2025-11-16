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

  list(const std::initializer_list<T>& l);
  list(const Allocator& alloc);
  list(const list& other);
  list(list&& other) noexcept;
  ~list();

  void push_back(const T& elem);

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

    T data;
    node_ptr prev;
    node_ptr next;
  };
};

template <class T, class Allocator>
list<T, Allocator>::list(const std::initializer_list<T>& l)
    : m_allocator(alloc) {
  for (const auto& elem : l) {
    push_back(elem);
  }
}

template <class T, class Allocator>
list<T, Allocator>::list(const Allocator& alloc) : m_allocator(alloc) {}

template <class T, class Allocator>
list<T, Allocator>::list(const list<T, Allocator>& other) : m_allocator() {
  initialize_copy(other.begin(), other.end());
}

template <class T, class Allocator>
list<T, Allocator>::list(list<T, Allocator>&& other) noexcept
    : m_allocator(other.m_allocator) {
  initialize_move(other.begin(), other.end());
}

template <class T, class Allocator>
list<T, Allocator>::~list() {
  iterator curr = m_head;
  while (curr != nullptr) {
    iterator next = curr->next;
    std::destroy_at(curr);
    m_allocator.deallocate(curr, 1);
    curr = next;
  }
}

template <class T, class Allocator>
void list<T, Allocator>::push_back(const T& elem) {
  iterator curr = m_allocator.allocate(1);
  std::construct_at(curr, elem);
  if (!m_head) {
    m_tail = curr;
    m_head = m_tail;
    return;
  }
  m_tail->next = curr;
  curr->prev = m_tail;
  m_tail = m_tail->next;
}

}  // namespace cool