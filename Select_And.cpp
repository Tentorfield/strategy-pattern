#include "Select_And.hpp"
#include <iostream>

using namespace std;

       Select_And::~Select_And(){
		delete this->value1;
		delete this->value2;
	}

       Select_And::Select_And(Select* first, Select* second){
		this->value1 = first;
		this->value2 = second;
	}

       bool Select_And::select(const Spreadsheet* sheet, int row) const{
		if (value1->select(sheet, row) == true && value2->select(sheet, row) == true){
			return true;
		}
		else{
			return false;
		}
       }
