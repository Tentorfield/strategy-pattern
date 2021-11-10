#include "gtest/gtest.h"
#include "spreadsheet.hpp"
#include "spreadsheet.cpp"
#include "contains_test.hpp"
#include "select_and_test.cpp"
//#include "select.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
