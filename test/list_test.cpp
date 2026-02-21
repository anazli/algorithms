#include <cool/containers/sequential/list.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <cmath>

using testing::Eq;

using namespace cool;

class ListTest : public testing::Test {
 public:
};

TEST_F(ListTest, GivenNoInputSizeWhenListIsCreatedThenItIsEmpty) {
  cool::list<int> l;

  EXPECT_THAT(l.size(), Eq(0));
  ASSERT_TRUE(l.empty());
}

TEST_F(ListTest, GivenInputElementWhenListIsCreatedThenItsSizeIsCorrect) {
  cool::list<int> l;
  l.push_back(1);

  EXPECT_THAT(l.size(), Eq(1));
  ASSERT_FALSE(l.empty());
}

TEST_F(ListTest, GivenInitializerListWhenListIsCreatedThenItsSizeIsCorrect) {
  std::initializer_list<int> init_list = {1, 2, 3, 4};
  cool::list<int> l(init_list);

  EXPECT_THAT(l.size(), Eq(init_list.size()));
  EXPECT_FALSE(l.empty());
  EXPECT_THAT(l.front(), Eq(1));
  ASSERT_THAT(l.back(), Eq(4));
}

TEST_F(ListTest, GivenInputWhenElemsAreAddedAndRemovedBackThenItIsCorrect) {
  cool::list<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.pop_back();
  l.push_back(4);
  l.pop_back();
  l.pop_back();

  EXPECT_THAT(l.size(), Eq(1));
  EXPECT_FALSE(l.empty());
  EXPECT_THAT(l.front(), Eq(1));
  ASSERT_THAT(l.back(), Eq(1));
}

TEST_F(ListTest, GivenInputWhenElemsAreAddedAndRemovedFrontThenItIsCorrect) {
  cool::list<int> l;
  l.push_front(1);
  l.push_front(2);
  l.push_front(3);
  l.pop_front();
  l.push_front(4);
  l.pop_front();
  l.pop_front();

  EXPECT_THAT(l.size(), Eq(1));
  EXPECT_FALSE(l.empty());
  EXPECT_THAT(l.front(), Eq(1));
  ASSERT_THAT(l.back(), Eq(1));
}

TEST_F(ListTest, GivenInputWhenElemsAreAddedAndRemovedThenItIsCorrect) {
  cool::list<int> l;
  l.push_front(1);
  l.push_front(2);
  l.push_back(3);
  l.pop_front();
  l.push_back(4);
  l.push_front(5);
  l.pop_back();

  EXPECT_THAT(l.size(), Eq(3));
  EXPECT_FALSE(l.empty());
  EXPECT_THAT(l.front(), Eq(5));
  ASSERT_THAT(l.back(), Eq(3));
}

TEST_F(ListTest, GivenNonEmptyListWhenItsClearedThenAllElementsAreGone) {
  cool::list<int> l;
  l.push_back(1);
  l.push_front(2);
  l.push_back(3);
  l.push_front(4);
  l.clear();

  EXPECT_THAT(l.size(), Eq(0));
  ASSERT_TRUE(l.empty());
}