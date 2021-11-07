#include "Select.hpp"

class Select : SelectAnd { // subclass of Strategy "Select"
    private:


    public: 
	SelectAnd(Select*);
	virtual ~Select();

        // Return true if the specified row should be selected.
        virtual bool select(const Spreadsheet* sheet, int row);

};
