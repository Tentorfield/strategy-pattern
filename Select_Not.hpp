#ifndef __SELECT_NOT_HPP__
#define __SELECT_NOT_HPP__

#include "select.hpp"

class Select_Not: public Select {
   private:
        Select* selection;

   public:

	// is passed in a new Select_Contains object
        Select_Not(Select* selection);

        ~Select_Not();

        // Return false if the specified row should be selected.
        virtual bool select(const Spreadsheet* sheet, int row) const;

};

#endif //__SELECT_NOT_HPP__ 
