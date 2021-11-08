#include "select.hpp"

class Select_Not : public Select { // subclass of Strategy "Select"
    private:


    public: 
	Select_Not(Select*);
	virtual ~Select();

        // Return true if the specified row should be selected.
        virtual bool select(const Spreadsheet* sheet, int row);

};
