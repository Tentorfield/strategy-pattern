#include "select.hpp"

class Select_Not : public Select { // subclass of Strategy "Select"
    protected:
	Select* selection;

    public: 
	// is passed in a new Select_Contains object
	Select_Not(Select* selection);
	~Select_Not();
        // Return true if the specified row should be selected.
        bool select(const Spreadsheet* sheet, int row) const;

};
