#include "spreadsheet.hpp"
#include "gtest/gtest.h"

#include "contains_test.hpp"
//#include "select_and_test.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
