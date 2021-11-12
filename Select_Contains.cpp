#include <iostream>
#include "Select_Contains.hpp"
using namespace std;

Select_Contains::Select_Contains(Spreadsheet* sheet,const string &firstOrLast, const string &name){

    this->sheet = sheet;
    this->name = name;
    this->columnNum = sheet->get_column_by_name(firstOrLast);

}

//Select_Contains::~Select_Contains(){
//	delete this->sheet;
//}

// returns true if the row should be printed and false if should be ignored
bool Select_Contains::select(const Spreadsheet* sheet, int row) const{
    size_t s = sheet->cell_data(row, this->columnNum).find(this->name);
    if (s != std::string::npos) { 
	return true;
    }	
    else{
	return false;
    }
}

