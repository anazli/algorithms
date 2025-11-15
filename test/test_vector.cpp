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

TEST_F(VectorTest, Given2VectorsWhenOneIsConstructedFromOtherThenTheyAreEqual) {
  auto val = acos(-1);
  cool::vector<double> a(2, val);
  cool::vector<double> b(a);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a[0], b[0]);
  ASSERT_EQ(a[1], b[1]);
}

TEST_F(VectorTest, Given2VectorsWhenOneIsAsignedToOtherThenTheyAreEqual) {
  auto val = acos(-1);
  cool::vector<int> a(2, val);
  cool::vector<int> b(5, 0);
  b = a;
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a[0], b[0]);
  ASSERT_EQ(a[1], b[1]);
}