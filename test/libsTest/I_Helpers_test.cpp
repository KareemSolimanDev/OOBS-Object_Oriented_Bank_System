#include <string>
#include "../../include/Ktest/Ktest.h"
#include "../../include/libs/I_Helpers/Input_helpers.h"

using std::string;

//==================================================
//============="readInt() function Test"============
void readInt_Test()
{
    Ktest readInt_Test("readInt() function Test");
    readInt_Test.EXPECT_EQ(readInt_Test.INSERT_INPUT("400",Input_helpers::readInt),(long long)400);
    readInt_Test.EXPECT_EQ(readInt_Test.INSERT_INPUT("",Input_helpers::readInt),(long long)0);
    readInt_Test.DISPLAY_DATA();
}
//==================================================

//==================================================
//============="readFloat() function Test"============
void readFloat_Test()
{
    Ktest readFloat_Test("readFloat() function Test");
    readFloat_Test.EXPECT_EQ(readFloat_Test.INSERT_INPUT("400.8",Input_helpers::readFloat),(double)400.8);
    readFloat_Test.EXPECT_EQ(readFloat_Test.INSERT_INPUT("400.80",Input_helpers::readFloat),(double)400.8);
    readFloat_Test.EXPECT_EQ(readFloat_Test.INSERT_INPUT("",Input_helpers::readFloat),(double)0);
    readFloat_Test.DISPLAY_DATA();
}
//==================================================

//==================================================
//============="readStr() function Test"============
void readStr_Test()
{
    Ktest readStr_Test("readStr() function Test");
    readStr_Test.EXPECT_EQ(readStr_Test.INSERT_INPUT("",Input_helpers::readStr),(string)"");
    readStr_Test.EXPECT_EQ(readStr_Test.INSERT_INPUT(" ",Input_helpers::readStr),(string)" ");
    readStr_Test.EXPECT_EQ(readStr_Test.INSERT_INPUT("kemoo",Input_helpers::readStr),(string)"kemoo");
    readStr_Test.EXPECT_EQ(readStr_Test.INSERT_INPUT("kemoo kemoo",Input_helpers::readStr),(string)"kemoo kemoo");
    readStr_Test.DISPLAY_DATA();
}
//==================================================

//==================================================
//============"isNumInRange() function Test"===========
void isNumInRange_Test()
{
    Ktest isNumInRange_Test("isNumInRange() function Test");
    isNumInRange_Test.EXPECT_TRUE(Input_helpers::isNumInRange(15,1,100));
    isNumInRange_Test.EXPECT_FALSE(Input_helpers::isNumInRange(110,1,100));// 110 out of range(1:100)!
    isNumInRange_Test.EXPECT_TRUE(Input_helpers::isNumInRange(15.6,1.2,100.2));
    isNumInRange_Test.EXPECT_FALSE(Input_helpers::isNumInRange(100.1,1.0,100.0));// 100.1 out of range(1.0:100.0)!
    isNumInRange_Test.DISPLAY_DATA();
}
//==================================================


int main()
{

    readInt_Test();
    readFloat_Test();
    readStr_Test();
    isNumInRange_Test();

    return 0;
}

