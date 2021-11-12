#ifndef _NOT_TEST_HPP_
#define _NOT_TEST_HPP_

#include "gtest/gtest.h"
#include "contains_test.hpp"
#include "Select_Not.cpp"
#include <fstream>

TEST(Select_Not_Test, EvaluateLast) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "Grade" });
   sheet.add_row({ "John", "Smith", "Senior" });
   sheet.add_row({ "Sarah", "Smith", "Senior" });
   sheet.add_row({ "Sal", "Young", "Senior" });
   sheet.add_row({ "Jane", "Young", "Senior" });
   sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "Last", "Young"))); 
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "John Smith Senior \nSarah Smith Senior \n");
}

TEST(Select_Not_Test, EvaluateFirst) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "Grade" });
   sheet.add_row({ "John", "Smith", "Senior" });
   sheet.add_row({ "Sarah", "Smith", "Senior" });
   sheet.add_row({ "Sal", "Young", "Senior" });
   sheet.add_row({ "Jane", "Young", "Senior" });
   sheet.set_selection(
	new Select_Not(
		new Select_Contains(&sheet, "First", "S"))); 
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "John Smith Senior \nJane Young Senior \n");
}

TEST(Select_Not_Test, EvaluateNone) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "Grade" });
   sheet.add_row({ "John", "Smith", "Senior" });
   sheet.add_row({ "Sarah", "Smith", "Senior" });
   sheet.add_row({ "Sal", "Young", "Senior" });
   sheet.add_row({ "Jane", "Young", "Senior" });
   sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "Grade", "Senior"))); 
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "");
}


#endif //_NOT_TEST_HPP_
