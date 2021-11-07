
#include "Select.hpp"

class Select : SelectNot { // subclass of Strategy "Select"
    private:


    public: 
	SelectNot(Select*);
	virtual ~Select();

        // Return true if the specified row should be selected.
        virtual bool select(const Spreadsheet* sheet, int row);

};
