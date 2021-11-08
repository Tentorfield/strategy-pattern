
#include "Select_Contains.hpp"

SelectContains::SelectContains(Select* sheet, string firstOrLast, string name){

this = sheet;
this->name = name;
this->column = get_column_by_name(firstOrLast);

}


Select_Contains::~Select() {

delete this;

}


// returns true if the row should be printed and false if should be ignored
virtual bool SelectContains::select(const Spreadsheet* sheet, int row){

    if (name == sheet->cell_data(row, column) { 
	return true;
    }	
}

