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

bool Input_helpers::isIntInRange(int num,int min,int max)
{
    return (num >= min && num <= max);
}