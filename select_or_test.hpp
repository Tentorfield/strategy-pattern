#ifndef __SELECT_OR_TEST_HPP__
#define __SELECT_OR_TEST_HPP__

#include "gtest/gtest.h"
#include "Select_Or.cpp"
//#include "Select_Contains.cpp"
#include "spreadsheet.hpp"

TEST(Select_Or_Test, EvaluateNamesOrBothTrue) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "Grade" });
   sheet.add_row({ "Eugene", "Baldonado", "Senior" });
   sheet.add_row({ "Dong", "Liu", "Junior" });
   sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "First", "Eugene"), 
   	new Select_Contains(&sheet, "Last", "Baldonado")));
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "Eugene Baldonado Senior \n");
}

TEST(Select_Or_Test, EvaluateNameGradeOneTrue) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First","Last","Age", "Grade" });
   sheet.add_row({ "Eugene","Baldonado","22","Senior" });
   sheet.add_row({ "Harrison","Cooper","19","Junior" });
   sheet.add_row({ "Huy","Ngo","21","Senior" });
   sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "First", "Eugene"),
  	 new Select_Or(new Select_Contains(&sheet, "Age", "24"), new Select_Contains(&sheet, "Grade", "Baldonado"))));
   std::stringstream out;
   sheet.print_selection(out);
   EXPECT_EQ(out.str(),"Eugene Baldonado 22 Senior \n");
}

TEST(Select_Or_Test, EvaluateNoneTrue) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "MonthOfBirth" });
   sheet.add_row({ "Eugene", "Baldonado", "9" });
   sheet.add_row({ "Harrison", "Cooper", "8" });
   sheet.add_row({ "Huy", "Ngo", "2" });
   sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "First", "d"),
   	new Select_Contains(&sheet, "Last", "f")));
   std::stringstream out;
   sheet.print_selection(out);
   EXPECT_EQ(out.str(), "");
}

#endif
