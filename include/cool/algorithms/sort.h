#pragma once

#include "cool/containers/sequential/vector.h"

namespace cool {

template <typename T>
void insertion_sort(cool::vector<T>& v) {
  for (int i = 0; i < v.size(); ++i) {
    int current = i;
    while (current > 0 && v[current] < v[current - 1]) {
      std::swap(v[current], v[current - 1]);
      current--;
    }
  }
}

}  // namespace cool