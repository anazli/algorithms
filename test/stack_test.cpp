#include <cool/containers/sequential/stack.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

using testing::Eq;
using namespace cool;

class StackTest : public testing::Test {
 public:
  stack<std::string> st;
  std::string test = std::string("test");
};

TEST_F(StackTest, GivenTypeWhenItsCreatedThenItsEmpty) {
  EXPECT_THAT(st.size(), Eq(0));
  ASSERT_TRUE(st.empty());
}

TEST_F(StackTest, GivenEmptyStackWhenPushElemThenItsCorrectlyAdded) {
  st.push(test);

  EXPECT_THAT(st.top(), Eq(test));
  EXPECT_THAT(st.size(), Eq(1));
  ASSERT_FALSE(st.empty());
}