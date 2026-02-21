#include <cool/containers/sequential/vector.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <cmath>

using testing::Eq;

using namespace cool;

class VectorTest : public testing::Test {
 public:
};

TEST_F(VectorTest, GivenNoInputSizeWhenVectorIsCreatedThenItIsEmpty) {
  cool::vector<int> v;

  EXPECT_THAT(v.size(), Eq(0));
  ASSERT_TRUE(v.empty());
}

TEST_F(VectorTest, GivenInputSizeWhenVectorIsCreatedThenItsSizeIsCorrect) {
  auto n = 100;
  cool::vector<int> v(n);

  EXPECT_THAT(v.size(), Eq(n));
  ASSERT_FALSE(v.empty());
}

TEST_F(VectorTest,
       GivenInputSizeAndValueWhenVectorIsCreatedThenAllElementsAreInitialized) {
  auto n = 100;
  auto val = acos(-1);
  cool::vector<double> v(n, val);

  ASSERT_THAT(v.size(), Eq(n));
  for (auto& elem : v) {
    EXPECT_THAT(elem, Eq(val));
  }
}

TEST_F(VectorTest, Given2VectorsWhenOneIsCopiedToOtherThenTheyAreEqual) {
  auto val = acos(-1);
  cool::vector<double> a(2, val);
  cool::vector<double> b(a);

  EXPECT_THAT(b.size(), Eq(a.size()));
  EXPECT_THAT(b[0], Eq(a[0]));
  ASSERT_THAT(b[1], Eq(a[1]));
}

TEST_F(VectorTest, Given2VectorsWhenOneIsMovedToOtherThenTheyAreEqual) {
  auto val = acos(-1);
  cool::vector<double> a(2, val);
  cool::vector<double> b(std::move(a));

  EXPECT_THAT(b.size(), Eq(a.size()));
  EXPECT_THAT(b[0], Eq(a[0]));
  ASSERT_THAT(b[1], Eq(a[1]));
}

TEST_F(VectorTest, Given2VectorsWhenOneIsCopyAsignedToOtherThenTheyAreEqual) {
  auto val = acos(-1);
  cool::vector<int> a(2, val);
  cool::vector<int> b(5, 0);
  b = a;

  EXPECT_THAT(b.size(), Eq(a.size()));
  EXPECT_THAT(b[0], Eq(a[0]));
  ASSERT_THAT(b[1], Eq(a[1]));
}

TEST_F(VectorTest, Given2VectorsWhenOneIsMoveAsignedToOtherThenTheyAreEqual) {
  auto val = acos(-1);
  cool::vector<int> a(2, val);
  cool::vector<int> b(5, 0);
  b = std::move(a);

  EXPECT_THAT(b.size(), Eq(a.size()));
  EXPECT_THAT(b[0], a[0]);
  ASSERT_THAT(b[1], a[1]);
}

TEST_F(VectorTest, GivenExistingVectorWhenElementIsAddedThenVectorContainsIt) {
  auto n = 5;
  cool::vector<int> v(n, 0);
  v.push_back(9);

  EXPECT_THAT(v.size(), Eq(n + 1));
  ASSERT_THAT(v[v.size() - 1], Eq(9));
}