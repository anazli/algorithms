#include <cool/algorithms/sort.h>
#include <cool/containers/sequential/vector.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::Eq;

using namespace cool;

class SortTest : public testing::Test {
 public:
  cool::vector<int> v = {5, 3, 9, 0, 4, 5, 2, 6, 8};

  template <typename T>
  void print(const cool::vector<T>& v) {
    for (int i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
    std::cout << std::endl;
  }
};

TEST_F(SortTest, GivenNoneEmptyVectorWhenPassedToInsertionSortThenItsSorted) {
  cool::insertion_sort(v);

  // print(v);
  for (int i = 1; i < v.size(); ++i) {
    ASSERT_THAT(v[i], testing::Ge(v[i - 1]));
  }
}

TEST_F(SortTest, GivenNoneEmptyVectorWhenPassedToSelectionSortThenItsSorted) {
  cool::selection_sort(v);

  // print(v);
  for (int i = 1; i < v.size(); ++i) {
    ASSERT_THAT(v[i], testing::Ge(v[i - 1]));
  }
}

TEST_F(SortTest, GivenNoneEmptyVectorWhenPassedToBubbleSortThenItsSorted) {
  cool::bubble_sort(v);

  print(v);
  for (int i = 1; i < v.size(); ++i) {
    ASSERT_THAT(v[i], testing::Ge(v[i - 1]));
  }
}