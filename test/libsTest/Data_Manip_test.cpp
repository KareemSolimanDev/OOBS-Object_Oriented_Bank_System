#include <string>
#include <vector>

#include "../../include/Ktest/Ktest.h"
#include "../../include/libs/Data_Manip/DataManip_helpers.h"

using std::string;
using std::vector;

//==================================================
//======="SplitWords() function Test"=========
void SplitWords_Test()
{
    Ktest SplitWords_Test("SplitWords() function Test");

    vector<string> output=DataManip_helpers::SplitWords("Hi iam Kareem.");
    SplitWords_Test.EXPECT_EQ(output,{"Hi","iam","Kareem."});

    output= DataManip_helpers::SplitWords("Hi iam Kareem.","");
    SplitWords_Test.EXPECT_EQ(output,{"Hi iam Kareem."});

    output= DataManip_helpers::SplitWords("Hi,iam,Kareem.",",");
    SplitWords_Test.EXPECT_EQ(output,{"Hi","iam","Kareem."});

    SplitWords_Test.DISPLAY_DATA();
}
//==================================================

//==================================================
//======="JoinWords() function Test"=========
void JoinWords_Test()
{
    Ktest JoinWords_Test("JoinWords() function Test");

    string output=DataManip_helpers::JoinWords({"Hi","iam","Kareem."});
    JoinWords_Test.EXPECT_EQ(output,(string)"Hi iam Kareem.");

    output= DataManip_helpers::JoinWords({"Hi iam Kareem."});
    JoinWords_Test.EXPECT_EQ(output,(string)"Hi iam Kareem.","");

    output= DataManip_helpers::JoinWords({"Hi","iam","Kareem."},",");
    JoinWords_Test.EXPECT_EQ(output,(string)"Hi,iam,Kareem.");

    JoinWords_Test.DISPLAY_DATA();
}
//==================================================

int main()
{

    SplitWords_Test();
    JoinWords_Test();


    return 0;
}