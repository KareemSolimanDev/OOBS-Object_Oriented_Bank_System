#include <string>
#include <vector>

#include "../../include/Ktest/Ktest.h"
#include "../../include/libs/Data_Manip/DataManip_helpers.h"

using std::string;
using std::vector;

//==================================================
//======="SplitWords() function Test"==============
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
//======="JoinWords() function Test"================

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

//==================================================
//======="Ltrim() function Test"====================

void Ltrim_Test()
{
    Ktest Ltrim_Test("Ltrim() function Test");

    string output=DataManip_helpers::Ltrim("  kareem");
    Ltrim_Test.EXPECT_EQ(output,(string)"kareem");
    
    output=DataManip_helpers::Ltrim("  kareem  ");
    Ltrim_Test.EXPECT_EQ(output,(string)"kareem  ");

    Ltrim_Test.DISPLAY_DATA();
}
//==================================================

//==================================================
//======="Rtrim() function Test"====================

void Rtrim_Test()
{
    Ktest Rtrim_Test("Rtrim() function Test");

    string output=DataManip_helpers::Rtrim("Kareem    ");
    Rtrim_Test.EXPECT_EQ(output,(string)"Kareem");
    
    output=DataManip_helpers::Rtrim("  Kareem    ");
    Rtrim_Test.EXPECT_EQ(output,(string)"  Kareem");

    Rtrim_Test.DISPLAY_DATA();
}
//==================================================

//==================================================
//======="Trim() function Test"=====================

void Trim_Test()
{
    Ktest Trim_Test("Trim() function Test");

    string output=DataManip_helpers::Trim("      Kareem.       ");
    Trim_Test.EXPECT_EQ(output,(string)"Kareem.");


    Trim_Test.DISPLAY_DATA();
}
//==================================================

//==================================================
//======="ToUpper() function Test"=====================

void ToUpper_Test()
{
    Ktest ToUpper_Test("ToUpper() function Test");

    string output=DataManip_helpers::ToUpper("Kareem.");
    ToUpper_Test.EXPECT_EQ(output,(string)"KAREEM.");


    ToUpper_Test.DISPLAY_DATA();
}
//==================================================

//==================================================
//======="ToLower() function Test"=====================

void ToLower_Test()
{
    Ktest ToLower_Test("ToLower() function Test");

    string output=DataManip_helpers::ToLower("KAREEM");
    ToLower_Test.EXPECT_EQ(output,(string)"kareem");


    ToLower_Test.DISPLAY_DATA();
}
//==================================================

int main()
{

    SplitWords_Test();
    JoinWords_Test();
    Ltrim_Test();
    Rtrim_Test();
    Trim_Test();
    ToUpper_Test();
    ToLower_Test();


    return 0;
}