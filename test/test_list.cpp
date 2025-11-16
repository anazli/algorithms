#include <cool/containers/sequential/list.h>
#include <gtest/gtest.h>

#include <cmath>

using namespace cool;

class ListTest : public testing::Test {
 public:
};

TEST_F(ListTest, GivenNoInputSizeWhenListIsCreatedThenItIsEmpty) {
  cool::list<int> l;
  ASSERT_EQ(0, l.size());
  ASSERT_TRUE(l.empty());
}

TEST_F(ListTest, GivenInputElementWhenListIsCreatedThenItsSizeIsCorrect) {
  cool::list<int> l;
  l.push_back(1);
  ASSERT_EQ(1, l.size());
  ASSERT_FALSE(l.empty());
}
