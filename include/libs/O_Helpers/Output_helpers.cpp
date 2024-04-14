#include "Output_helpers.h"


string output_helpers::repeat(char letter, unsigned short Count)
{
    string word = "";
    for (short i = 0; i < Count; i++)
    {
        word += letter;
    }
    return word;
}
string output_helpers::repeat(string word, unsigned short Count)
{
    string sentence = "";
    for (short i = 0; i < Count; i++)
    {
        sentence += word;
    }
    return sentence;
}
