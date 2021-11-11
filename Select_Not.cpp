#include "Select_Not.hpp"

// is passed in a new Select_Contains object
Select_Not::Select_Not(Select* selection) {
    this->selection = selection;
}

Select_Not::~Select_Not() {
    delete this->selection;
}

// Return false if the specified row should be selected.
bool Select_Not::select(const Spreadsheet* sheet, int row) const {
    return !(this->selection->select(sheet, row));
}

