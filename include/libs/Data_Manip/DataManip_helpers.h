#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;


class DataManip_helpers
{
public:

    static vector<string> SplitWords(string sentence, string delim);
    static string JoinWords(vector<string> words, string delim);

};
#include "DataManip_helpers.cpp"


