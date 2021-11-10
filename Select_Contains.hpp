#ifndef __SELECT_CONTAINS_HPP__
#define __SELECT_CONTAINS_HPP__

#include "select.hpp"
using namespace std;

class Select_Contains : public Select { // subclass of Strategy "Select"
    private:
	int column;
	string name;
	Spreadsheet* sheet;

    public: 
	Select_Contains(Spreadsheet*, string, string);
        
        ~Select_Contains() { delete sheet; }

        // Return true if the specified row should be selected.
        virtual bool select(const Spreadsheet* sheet, int row) const;

};

#endif //__SELECT_CONTAINS_HPP__ 
