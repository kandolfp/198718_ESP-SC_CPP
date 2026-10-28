// math_utils_test.cpp
#include "math_utils.hpp"
#include <gtest/gtest.h>

// Test case for the add function
TEST(MathUtilsTest, AddFunction) {
  EXPECT_EQ(add(2, 3), 5);  // 2 + 3 = 5
  EXPECT_EQ(add(-1, 1), 0); // -1 + 1 = 0
  EXPECT_EQ(add(0, 0), 0);  // 0 + 0 = 0
}

// Test case for the subtract function
TEST(MathUtilsTest, SubtractFunction) {
  EXPECT_EQ(sub(5, 3), 2);   // 5 - 3 = 2
  EXPECT_EQ(sub(0, 1), -1);  // 0 - 1 = -1
  EXPECT_EQ(sub(10, 10), 0); // 10 - 10 = 0
}

// Main function to run all tests
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}