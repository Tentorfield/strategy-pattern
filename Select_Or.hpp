
#include "Select.hpp"

class Select : SelectOr { // subclass of Strategy "Select"
    private:


    public: 
	SelectOr(Select*);
	virtual ~Select();

        // Return true if the specified row should be selected.
        virtual bool select(const Spreadsheet* sheet, int row);

};
