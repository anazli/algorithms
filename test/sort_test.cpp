#include <cool/algorithms/sort.h>
#include <cool/containers/sequential/vector.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::Eq;

using namespace cool;

class SortTest : public testing::Test {
 public:
};

TEST_F(SortTest, GivenNoneEmptyVectorWhenPassedToInsertionSortThenItsSorted) {
  cool::vector<int> v = {5, 3, 9, 0, 4, 5, 2, 6, 8};
  cool::insertion_sort(v);

  for (int i = 1; i < v.size(); ++i) {
    ASSERT_THAT(v[i], testing::Ge(v[i - 1]));
  }
}
