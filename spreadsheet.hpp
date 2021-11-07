#ifndef __SPREADSHEET_HPP__
#define __SPREADSHEET_HPP__

#include <string>
#include <initializer_list>
#include <vector>
#include <iosfwd>

class Select;

class Spreadsheet
{
    std::vector<std::string> column_names;
    std::vector<std::vector<std::string> > data;
    Select* select = nullptr;

public:
    ~Spreadsheet();

    const std::string& cell_data(int row, int column) const
    {
        return data.at(row).at(column); // finds data at coordinates
    }

    std::string& cell_data(int row, int column)
    {
        return data.at(row).at(column); // same but not const
    }

    void set_selection(Select* new_select); // sets the object (select) pointer

    // TODO: Implement print_selection.
    void print_selection(std::ostream& out) const;
    // prints to out the contents of the selected rows
    // This routine should visit the rows of the spreadsheet in order, 
    // querying the selection object to decide whether the routine should 
    // be printed or ignored. If the select pointer is null, 
    // all rows should be printed

    void clear();
    void set_column_names(const std::vector<std::string>& names);
    void add_row(const std::vector<std::string>& row_data);
    int get_column_by_name(const std::string& name) const;
};

#endif //__SPREADSHEET_HPP__
