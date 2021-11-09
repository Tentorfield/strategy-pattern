#include "select.hpp"

class Select_Not : public Select { // subclass of Strategy "Select"
    private:
	int column;
	string name;
	Spreadsheet* sheet;

    public: 
	// is passed in a new Select_Contains object
	Select_Not(Select_Contains*);

        // Return true if the specified row should be selected.
        bool select(const Spreadsheet* sheet, int row);

};
