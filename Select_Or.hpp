#ifndef __SELECT_OR_HPP__
#define __SELECT_OR_HPP__

#include "select.hpp"

class Select_Or : public Select { // subclass of Strategy "Select"
    protected:
	Select* value1 = nullptr;
	Select* value2 = nullptr;

    public:
	~Select_Or();

        // Return true if the specified row should be selected.
	Select_Or(Select* first, Select* second);

        bool select(const Spreadsheet* sheet, int row) const;

};

#endif
