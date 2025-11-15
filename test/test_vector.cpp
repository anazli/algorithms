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