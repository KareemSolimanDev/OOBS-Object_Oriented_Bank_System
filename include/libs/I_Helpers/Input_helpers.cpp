#include "Input_helpers.h"


string Input_helpers::readStr()
{
    string input ="";
    std::getline(cin, input);
    return input;
}

long long Input_helpers::readInt()
{
    long long input = 0;
    std::cin >> input;
    cin.ignore();
    cin.clear();
    return input;
}

double Input_helpers::readFloat()
{
    double input = 0;
    std::cin >> input;
    cin.ignore();
    cin.clear();
    return input;
}

template<typename T>
bool Input_helpers::isNumInRange(T num,T min,T max)
{
    return (num >= min && num <= max);
}