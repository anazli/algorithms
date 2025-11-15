#include <cool/containers/sequential/vector.h>
#include <gtest/gtest.h>

#include <cmath>

using namespace cool;

class VectorTest : public testing::Test {
 public:
};

TEST_F(VectorTest, GivenNoInputSizeWhenVectorIsCreatedThenItIsEmpty) {
  cool::vector<int> v;
  ASSERT_EQ(0, v.size());
}

TEST_F(VectorTest, GivenInputSizeWhenVectorIsCreatedThenItsSizeIsCorrect) {
  auto n = 100;
  cool::vector<int> v(n);
  ASSERT_EQ(n, v.size());
}

TEST_F(VectorTest,
       GivenInputSizeAndValueWhenVectorIsCreatedThenAllElementsAreInitialized) {
  auto n = 100;
  auto val = acos(-1);
  cool::vector<double> v(n, val);
  ASSERT_EQ(n, v.size());
  for (auto& elem : v) {
    ASSERT_EQ(val, elem);
  }
}

TEST_F(VectorTest, Given2VectorsWhenOneIsCopiedToOtherThenTheyAreEqual) {
  auto val = acos(-1);
  cool::vector<double> a(2, val);
  cool::vector<double> b(a);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a[0], b[0]);
  ASSERT_EQ(a[1], b[1]);
}

TEST_F(VectorTest, Given2VectorsWhenOneIsMovedToOtherThenTheyAreEqual) {
  auto val = acos(-1);
  cool::vector<double> a(2, val);
  cool::vector<double> b(std::move(a));
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a[0], b[0]);
  ASSERT_EQ(a[1], b[1]);
}

TEST_F(VectorTest, Given2VectorsWhenOneIsCopyAsignedToOtherThenTheyAreEqual) {
  auto val = acos(-1);
  cool::vector<int> a(2, val);
  cool::vector<int> b(5, 0);
  b = a;
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a[0], b[0]);
  ASSERT_EQ(a[1], b[1]);
}

TEST_F(VectorTest, Given2VectorsWhenOneIsMoveAsignedToOtherThenTheyAreEqual) {
  auto val = acos(-1);
  cool::vector<int> a(2, val);
  cool::vector<int> b(5, 0);
  b = std::move(a);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a[0], b[0]);
  ASSERT_EQ(a[1], b[1]);
}

TEST_F(VectorTest, GivenExistingVectorWhenElementIsAddedThenVectorContainsIt) {
  auto n = 5;
  cool::vector<int> v(n, 0);
  v.push_back(9);
  ASSERT_EQ(n + 1, v.size());
  ASSERT_EQ(9, v[v.size() - 1]);
}