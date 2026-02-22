#pragma once

#include <memory>
#include <utility>

#include "error.h"

/*************************************************************
 *                    Doubly Linked List
 * -----------------------------------------------------------
 * A simplified version of stl list.
 **************************************************************/

namespace cool {

template <class T>
class Node {
 public:
  using node_ptr = Node<T>*;

  explicit Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}
  Node(const T& d, node_ptr p, node_ptr n) : data(d), prev(p), next(n) {}

  T data;
  node_ptr prev;
  node_ptr next;
};

template <class T, class Allocator = std::allocator<T>>
class list {
 public:
  using iterator = Node<T>*;
  using const_iterator = const Node<T>*;
  using size_type = size_t;
  using node_allocator =
      std::allocator_traits<Allocator>::template rebind_alloc<Node<T>>;

  list() = default;
  list(const std::initializer_list<T>& l, const Allocator& alloc = Allocator());
  list(const Allocator& alloc);
  // list(const list& other);
  list(list&& l) noexcept;
  ~list();

  list& operator=(list&& l) noexcept;

  void push_front(const T& elem);
  void pop_front();

  void push_back(const T& elem);
  void pop_back();

  size_type size() const { return m_size; }
  bool empty() const { return m_size == 0 && !m_head && !m_tail; }
  void clear();

  iterator begin() { return m_head; }
  const_iterator begin() const { return m_head; }

  iterator end() { return nullptr; }
  const_iterator end() const { return nullptr; }

  T& front() {
    ASSERT(m_head != nullptr, "cool::list::front() called on empty list");
    return m_head->data;
  }
  const T& front() const {
    ASSERT(m_head != nullptr, "cool::list::front() called on empty list");
    return m_head->data;
  }
  T& back() {
    ASSERT(m_head != nullptr, "cool::list::back() called on empty list");
    return m_tail->data;
  }
  const T& back() const {
    ASSERT(m_head != nullptr, "cool::list::back() called on empty list");
    return m_tail->data;
  }

 private:
  iterator create_node(const T& elem);

  iterator m_head = nullptr;
  iterator m_tail = nullptr;
  size_type m_size = 0;
  node_allocator m_allocator = std::allocator<T>();
};

template <class T, class Allocator>
list<T, Allocator>::list(const Allocator& alloc)
    : m_allocator(node_allocator(alloc)) {}

template <class T, class Allocator>
list<T, Allocator>::list(const std::initializer_list<T>& l,
                         const Allocator& alloc)
    : m_allocator(node_allocator(alloc)) {
  for (const auto& elem : l) {
    push_back(elem);
  }
}

template <class T, class Allocator>
list<T, Allocator>::list(list&& l) noexcept
    : m_head(l.m_head),
      m_tail(l.m_tail),
      m_size(l.m_size),
      m_allocator(l.m_allocator) {
  l.m_head = l.m_tail = nullptr;
  l.m_size = 0;
}

template <class T, class Allocator>
list<T, Allocator>::~list() {
  clear();
}

template <class T, class Allocator>
list<T, Allocator>& list<T, Allocator>::operator=(list&& l) noexcept {
  if (&l != this) {
    clear();

    m_head = l.m_head;
    m_tail = l.m_tail;
    m_size = l.m_size;

    l.m_head = l.m_tail = nullptr;
    l.m_size = 0;
  }
  return *this;
}

template <class T, class Allocator>
void list<T, Allocator>::push_front(const T& elem) {
  iterator it = create_node(elem);
  m_size++;

  if (!m_head) {
    m_tail = it;
    m_head = m_tail;
    return;
  }

  m_head->prev = it;
  it->next = m_head;
  m_head = it;
}

template <class T, class Allocator>
void list<T, Allocator>::pop_front() {
  if (!m_head || m_size == 0) return;

  if (m_size == 1) {
    std::destroy_at(m_head);
    m_allocator.deallocate(m_head, 1);
    m_head = m_tail = nullptr;
    m_size--;
    return;
  }

  iterator it = m_head->next;
  it->prev = nullptr;
  std::destroy_at(m_head);
  m_allocator.deallocate(m_head, 1);
  m_head = it;
  m_size--;
}
template <class T, class Allocator>
void list<T, Allocator>::push_back(const T& elem) {
  iterator it = create_node(elem);
  m_size++;

  if (!m_head) {
    m_tail = it;
    m_head = m_tail;
    return;
  }
  m_tail->next = it;
  it->prev = m_tail;
  m_tail = it;
}

template <class T, class Allocator>
void list<T, Allocator>::pop_back() {
  if (!m_tail || m_size == 0) return;

  if (m_size == 1) {
    std::destroy_at(m_tail);
    m_allocator.deallocate(m_tail, 1);
    m_head = m_tail = nullptr;
    m_size--;
    return;
  }

  iterator it = m_tail->prev;
  it->next = nullptr;
  std::destroy_at(m_tail);
  m_allocator.deallocate(m_tail, 1);
  m_tail = it;
  m_size--;
}

template <class T, class Allocator>
void list<T, Allocator>::clear() {
  iterator curr = m_head;
  while (curr) {
    iterator next = curr->next;
    std::destroy_at(curr);
    m_allocator.deallocate(curr, 1);
    curr = next;
    m_size--;
  }
  m_head = m_tail = nullptr;
}

template <class T, class Allocator>
list<T, Allocator>::iterator list<T, Allocator>::create_node(const T& elem) {
  iterator it = m_allocator.allocate(1);
  std::construct_at(it, elem);
  return it;
}

}  // namespace cool