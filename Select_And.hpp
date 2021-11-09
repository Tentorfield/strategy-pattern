#ifndef __SELECT_AND_HPP__ 
#define __SELECT_AND_HPP__

#include "select.hpp"

class Select_And: public Select
{
protected:
        Select* value1 = nullptr;
        Select* value2 = nullptr;

public:
        ~Select_And();

        Select_And(Select* first, Select* second);

        virtual bool select(const Spreadsheet* sheet, int row) const;
};

#endif
