#include "Select_Or.hpp"
#include <iostream>

using namespace std;

	Select_Or::~Select_Or(){
		delete this->value1;
		delete this->value2;
	}

	Select_Or::Select_Or(Select* first, Select* second){
		this->value1 = first;
		this->value2 = second;
	}

	bool Select_Or::select(const Spreadsheet* sheet, int row) const{
		if (value1->select(sheet,row) == true || value2->select(sheet, row) == true){
			return true;
		}
		else {
			return false;
		}
	}
