#include "Select.hpp"

class Selec_Or : public Select { // subclass of Strategy "Select"
    private:


    public: 
	Select_Or(Select*);
	virtual ~Select();

        // Return true if the specified row should be selected.
        virtual bool select(const Spreadsheet* sheet, int row);

};
