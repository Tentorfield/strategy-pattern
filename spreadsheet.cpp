#include "spreadsheet.hpp"
#include "select.hpp"

#include <algorithm>
#include <iostream>

using namespace std;

Spreadsheet::~Spreadsheet()
{
    delete select;
}

void Spreadsheet::set_selection(Select* new_select)
{
    delete select;
    select = new_select;
}

void Spreadsheet::clear()
{
    column_names.clear();
    data.clear();
    delete select;
    select = nullptr;
}

void Spreadsheet::set_column_names(const std::vector<std::string>& names)
{
    column_names=names;
}

void Spreadsheet::add_row(const std::vector<std::string>& row_data)
{
    data.push_back(row_data);
}

int Spreadsheet::get_column_by_name(const std::string& name) const
{
    for(int i=0; i<column_names.size(); i++)
        if(column_names.at(i) == name)
            return i;
    return -1;
}

// TODO: Implement print_selection.
void Spreadsheet::print_selection(std::ostream& out) const{
	if (select != nullptr){ // If select is not empty, forloop printing the specifics
		for (int row = 0; row < data.size(); row++){
			for (int column = 0; column < column_names.size(); column++){
				if (select->select(this, row) == true) { //if user did select a specific row print
					out << this->cell_data(row, column) << " ";
				}
			}
			if (select->select(this, row) == true){// next row
				out << endl;
			}
		}
	}
	else{ //else when select pointer is null print all rows
		for (int row = 0; row < data.size(); row++){
			for (int column = 0; column < column_names.size(); column++){
				out << this->cell_data(row, column) << " ";
			}
			out << endl;
		}
	}
}			
// prints to out the contents of the selected rows
// This routine should visit the rows of the spreadsheet in order, 
// querying the selection object to decide whether the routine should 
// be printed or ignored. If the select pointer is null, 
// all rows should be printed

