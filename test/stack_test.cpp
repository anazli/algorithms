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

TEST_F(StackTest, GivenEmptyStackWhenTopThenItsAnError) {
  EXPECT_DEATH(auto t = st.top(), "stack is empty");
}

TEST_F(StackTest, GivenNoneEmptyStackWhenPopElemThenItsCorrectlyRemoved) {
  st.push(test);
  st.pop();

  EXPECT_THAT(st.size(), Eq(0));
  ASSERT_TRUE(st.empty());
}

TEST_F(StackTest, GivenNoneEmptyStackWhenCopiedThenItsCopyIsValid) {
  st.push(test);
  auto other(st);

  EXPECT_THAT(other.size(), st.size());
  EXPECT_THAT(other.top(), st.top());
  ASSERT_FALSE(other.empty());
}

TEST_F(StackTest, GivenNoneEmptyStackWhenMovedThenTheNewStackIsValid) {
  st.push(test);
  auto elem = st.top();
  auto other(std::move(st));

  EXPECT_THAT(other.size(), 1);
  EXPECT_THAT(other.top(), elem);
  ASSERT_FALSE(other.empty());
}

TEST_F(StackTest, GivenNoneEmptyStackWhenCopyAssignedThenItsCopyIsValid) {
  st.push(test);
  stack<std::string> other;
  other = st;

  EXPECT_THAT(other.size(), st.size());
  EXPECT_THAT(other.top(), st.top());
  ASSERT_FALSE(other.empty());
}

TEST_F(StackTest, GivenNoneEmptyStackWhenMoveAssignedThenTheNewStackIsValid) {
  st.push(test);
  auto elem = st.top();
  stack<std::string> other;
  other = std::move(st);

  EXPECT_THAT(other.size(), 1);
  EXPECT_THAT(other.top(), elem);
  ASSERT_FALSE(other.empty());
}