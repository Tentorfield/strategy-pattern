#ifndef _NOT_TEST_HPP
#define _NOT_TEST_HPP

#include "gtest/gtest.h"
#include "Select_Contains.cpp"
#include "spreadsheet.hpp"
#include "contains_test.hpp"

TEST(NOT_Test, NotJim) {

    Spreadsheet* sheet;
    sheet->set_column_names({"First","Last","Age","Major"});
    sheet->add_row({"Amanda","Andrews","22","business"});
    sheet->add_row({"Jim","Becker","21","computer science"});
    sheet->add_row({"Carol","Conners","21","computer science"});

    Select* test = new Select_Contains(sheet, "first", "Jim");
    EXPECT_EQ(test->select(sheet, 2), true); 
}

#endif //_NOT_TEST_HPP

/*
TEST(Select_And_Test, EvalualteNamesAnd) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "Grade" });
   sheet.add_row({ "Huy", "Ngo", "Senior" });
   sheet.add_row({ "Dong", "Liu", "Junior" });
   sheet.set_selection(new Select_And(new Select_Contains(&sheet, "First", "Huy"), 
   new Select_Contains(&sheet, "Last", "Ngo")));
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "Huy Ngo Junior \n");
}
*/
