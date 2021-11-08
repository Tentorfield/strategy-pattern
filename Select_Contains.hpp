#include "Select.hpp"

class Select_Contains : public Select { // subclass of Strategy "Select"
    private:


    public: 
	Select_Contains(Select*);
	virtual ~Select();

        // Return true if the specified row should be selected.
        virtual bool select(const Spreadsheet* sheet, int row);

};
