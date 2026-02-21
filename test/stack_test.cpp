#include <cool/containers/sequential/stack.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::Eq;

using namespace cool;

class StackTest : public testing::Test {
 public:
};

TEST_F(StackTest, GivenTypeWhenItsCreatedThenItsEmpty) {
  stack<int> st;

  EXPECT_THAT(st.size(), Eq(0));
  ASSERT_TRUE(st.empty());
}