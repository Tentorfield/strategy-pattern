#ifndef _CONTAINS_TEST_HPP_
#define _CONTAINS_TEST_HPP_

#include "gtest/gtest.h"
#include "Select_Contains.cpp"
#include "spreadsheet.hpp"

TEST(Select_Contains_Test, EvaluateOneLine) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "Grade" });
   sheet.add_row({ "Eugene", "Baldonado", "Senior" });
   sheet.add_row({ "Dong", "Liu", "Junior" });
   sheet.set_selection(new Select_Contains(&sheet, "First", "Eugene")), 
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "Eugene Baldonado Senior \n");
}

TEST(Select_Contains_Test, EvaluateTwoLines) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First","Last","Age", "Grade" });
   sheet.add_row({ "Eugene","Baldonado","22","Senior" });
   sheet.add_row({ "Harrison","Cooper","19","Junior" });
   sheet.add_row({ "Huy","Ngo","21","Senior" });
   sheet.set_selection(new Select_Contains(new Select_Contains(&sheet, "Grade", "Senior"),
   std::stringstream out;
   sheet.print_selection(out);
   EXPECT_EQ(out.str(),"Eugene Baldonado 22 Senior \nHuy Ngo 21 Senior");
}

TEST(Select_Contains_Test, EvaluateNone) {
   Spreadsheet sheet;
   sheet.set_selection(new Select_Contains(new Select_Contains(&sheet, "First", "d"),
   new Select_Contains(&sheet, "Last", "f")));
   std::stringstream out;
   sheet.print_selection(out);
   EXPECT_EQ(out.str(), "");
}


#endif //_CONTAINS_TEST_HPP_
