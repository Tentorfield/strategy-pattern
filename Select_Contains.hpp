
#include "Select.hpp"

class Select : SelectContains { // subclass of Strategy "Select"
    private:


    public: 
	SelectContains(Select*);
	virtual ~Select();

        // Return true if the specified row should be selected.
        virtual bool select(const Spreadsheet* sheet, int row);

};
