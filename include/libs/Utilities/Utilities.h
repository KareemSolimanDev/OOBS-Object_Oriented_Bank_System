#pragma once
#include <string>
#include <vector>
#include <time.h>

using std::string;
using std::vector;

namespace Date
{
    struct Data
    {
        string year;
        string month;
        string day; 
        string hour;
        string minute; 
        string second; 
    };
    Data getCurrentDateTime();
    string getFormatedDate();
    string getFormatedTime();
} // namespace Date

#include "Utilities.cpp"