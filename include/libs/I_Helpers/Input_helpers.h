#pragma once
#include <iostream>


using std::string;
using std::endl;
using std::cout;
using std::cin;

class Input_helpers
{

public:

    static string readStr();
    
    static long long readInt();

    static bool isIntInRange(int num,int min=INT_MIN,int max=INT_MAX);

};
#include "Input_helpers.cpp"
