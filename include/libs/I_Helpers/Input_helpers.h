#pragma once
#include <iostream>


using std::string;
using std::cin;

class Input_helpers
{

public:

    static string readStr();
    
    static long long readInt();

    static double readFloat();

    template<typename T>
    static bool isNumInRange(T num,T min,T max);

};
#include "Input_helpers.cpp"
