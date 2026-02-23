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

template <typename T>
void selection_sort(cool::vector<T>& v) {
  auto n = v.size();
  for (int i = 0; i < n; ++i) {
    int indx = i;
    for (int j = i; j < n; ++j) {
      if (v[j] < v[indx]) {
        indx = j;
      }
    }
    std::swap(v[i], v[indx]);
  }
}

template <typename T>
void bubble_sort(cool::vector<T>& v) {
  int n = v.size();
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (v[j] > v[j + 1]) {
        std::swap(v[j + 1], v[j]);
      }
    }
  }
}

}  // namespace cool