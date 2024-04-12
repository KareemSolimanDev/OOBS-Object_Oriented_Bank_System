#pragma once
#include <iostream>

using std::string;

class output_helpers
{

public:
    static string repeat(char letter, unsigned short Count);
    static string repeat(string word, unsigned short Count);
};

#include "Output_helpers.cpp"