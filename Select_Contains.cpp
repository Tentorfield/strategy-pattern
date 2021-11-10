
#include "Select_Contains.hpp"

Select_Contains::Select_Contains(Spreadsheet* sheet, string firstOrLast, string name){

this->sheet = sheet;
this->name = name;
this->column = sheet->get_column_by_name(firstOrLast);

}



// returns true if the row should be printed and false if should be ignored
bool Select_Contains::select(const Spreadsheet* sheet, int row) const{

    if (name == sheet->cell_data(row, this->column)) { 
	return true;
    }	
    else{
	return false;
    }
}

