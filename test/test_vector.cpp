#include "cool/containers/sequential/vector.h"
#include "gtest/gtest.h"

TEST(vector, Dummy) {
  cool::vector<int> v;
  v.temp();
  SUCCEED();
}
