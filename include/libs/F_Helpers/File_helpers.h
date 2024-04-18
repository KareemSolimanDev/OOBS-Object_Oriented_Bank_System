#pragma once

#include <fstream>
#include <vector>

using std::string;
using std::vector;



class File_helpers
{
public:
    static void AppendDataToFile(string fileName, string Data);

    static void WriteDataOnFile(string fileName, vector<string> newData);

    static vector<string> GetDataFromFile(string fileName);
};
#include "File_helpers.cpp"
