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

bool Input_helpers::isIntInRange(int num,int min=INT_MIN,int max=INT_MAX)
{
    return (num >= min && num <= max);
}