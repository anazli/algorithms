#include "hello_world.h"
#include "gtest/gtest.h"

TEST(HelloWorld, Dummy) {
  HelloWorld hw;
  (void)hw;
  SUCCEED();
}
