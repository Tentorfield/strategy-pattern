#include "select.hpp"

class Select_Not : public Select { // subclass of Strategy "Select"
    private:
	int column;
	string name;
	Spreadsheet* sheet;

    public: 
	Select_Not(Spreadsheet*, string, string);

        // Return true if the specified row should be selected.
        bool select(const Spreadsheet* sheet, int row);

};
