#ifndef __SELECT_CONTAINS_HPP__
#define __SELECT_CONTAINS_HPP__
/*
#include "select.hpp"
#include <string>
using namespace std;
class Select_Contains : public Select { // subclass of Strategy "Select"
    protected:
	int column;
	string name;
	Spreadsheet* sheet = nullptr;

    public: 
	Select_Contains(Spreadsheet*, const string&, const string&);
        
        ~Select_Contains();

        // Return true if the specified row should be selected.
        virtual bool select(const Spreadsheet* sheet, int row) const;

};
*/

class Select_Contains: public Select {

protected:
    std::string name;
    int columnNum;
    Spreadsheet* sheet;
public:
    Select_Contains(Spreadsheet* sheet,const std::string& columnName,const std::string& value);

    bool select(const Spreadsheet* sheet, int row) const;
};
#endif //__SELECT_CONTAINS_HPP__ 
