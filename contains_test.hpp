#ifndef _CONTAINS_TEST_HPP
#define _CONTAINS_TEST_HPP

#include "gtest/gtest.h"
#include "Select_Contains.cpp"

TEST(Contains_Test, ContainsJim) {

    Spreadsheet* sheet;
    sheet->set_column_names({"First","Last","Age","Major"});
    sheet->add_row({"Amanda","Andrews","22","business"});
    sheet->add_row({"Jim","Becker","21","computer science"});
    sheet->add_row({"Carol","Conners","21","computer science"});

    select* test = new Select_Contains(sheet, "first", "Jim");
    EXPECT_EQ(test->select(sheet, 2), true); 
}
/*
    sheet.set_selection(new Select_Contains(&sheet,"Last","Dole"));
    sheet.print_selection(std::cout);

    EXPECT_EQ(test


sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});
*/

#endif //_CONTAINS_TEST_HPP
