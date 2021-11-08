#include "select.hpp"

class Select_Contains : public Select { // subclass of Strategy "Select"
    private:
	string column;
	int name;

    public: 
	select(Select*, string, string);
	virtual ~Select();

        // Return true if the specified row should be selected.
        virtual bool select(const Spreadsheet* sheet, int row);

};
