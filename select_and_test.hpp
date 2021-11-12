#ifndef __SELECT_AND_TEST_HPP__
#define __SELECT_AND_TEST_HPP__

#include "gtest/gtest.h"
#include "Select_And.cpp"
#include "contains_test.hpp"
#include "spreadsheet.hpp"

TEST(Select_And_Test, EvaluateNamesAnd) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "Grade" });
   sheet.add_row({ "Huy", "Ngo", "Senior" });
   sheet.add_row({ "Dong", "Liu", "Junior" });
   sheet.set_selection(new Select_And(new Select_Contains(&sheet, "First", "Huy"), 
   	new Select_Contains(&sheet, "Last", "Ngo")));
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "Huy Ngo Senior \n");
}

TEST(Select_And_Test, EvaluateAnimalsAnd) {
   Spreadsheet sheet;
   sheet.set_column_names({ "Name","Species","Age", "Legs" });
   sheet.add_row({ "Tucker","dog","3","4" });
   sheet.add_row({ "Daisy","horse","4","4" });
   sheet.add_row({ "Tom","cat","2","4" });
   sheet.add_row({ "Jerry","mouse","1","4" });
   sheet.add_row({ "Perry","bird","2","2" });
   sheet.set_selection(new Select_And(new Select_Contains(&sheet, "Species", "dog"),
  	 new Select_And(new Select_Contains(&sheet, "Age", "3"), new Select_Contains(&sheet, "Name", "Tucker"))));
   std::stringstream out;
   sheet.print_selection(out);
   EXPECT_EQ(out.str(), "Tucker dog 3 4 \n");
}

TEST(Select_And_Test, AndNothing) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "MonthOfBirth" });
   sheet.add_row({ "Orlean", "Lazaro", "10" });
   sheet.add_row({ "Carl", "Evans", "5" });
   sheet.add_row({ "Harold", "Jankins", "12" });
   sheet.add_row({ "Mat", "Huntar", "5" });
   sheet.set_selection(new Select_And(new Select_Contains(&sheet, "First", "z"),
   	new Select_Contains(&sheet, "Last", "q")));
   std::stringstream out;
   sheet.print_selection(out);
   EXPECT_EQ(out.str(), "");
}

#endif
