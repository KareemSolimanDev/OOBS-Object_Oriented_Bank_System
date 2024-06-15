#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;


class DataManip_helpers
{
public:

    static vector<string> SplitWords(string sentence, string delim=" ");
    static string JoinWords(vector<string> words, string delim=" ");
    static string Ltrim(string sentence);
    static string Rtrim(string sentence);
    static string Trim(string sentence);
    static string ToUpper(string sentence);
    static string ToLower(string sentence);

};
#include "DataManip_helpers.cpp"


