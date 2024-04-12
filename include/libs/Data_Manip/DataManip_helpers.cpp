#include "DataManip_helpers.h"


vector<string> DataManip_helpers::SplitWords(string sentence, string delim=" ")
{

    // this case found during testing
    if(delim=="")
    {
        return {sentence};
    }

    vector<string> words = {};
    string word = "";
    sentence += delim;
    short delimPos = 0;

    while ((delimPos = sentence.find(delim)) != string::npos)
    {
        word = sentence.substr(0, delimPos);
        if (word != "")
        {
            words.push_back(word);
        }
        sentence.erase(0, delimPos + delim.length());
    }
    return words;
}

string DataManip_helpers::JoinWords(vector<string> words, string delim=" ")
{
    string  sentence= "";

    for (string i : words)
    {
        sentence +=i+delim;
    }

    sentence.erase(sentence.length()-delim.length());

    return sentence;
}
