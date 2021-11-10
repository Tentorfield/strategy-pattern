#ifndef __SELECT_OR_HPP__
#define __SELECT_OR_HPP__

#include "select.hpp"

class Select_Or : public Select { // subclass of Strategy "Select"
    private://


    public: 
	Select_Or(Select*);
	virtual ~Select();

        // Return true if the specified row should be selected.
	Select_Or(Select* first, Select* second);

        virtual bool select(const Spreadsheet* sheet, int row);

};

#endif
