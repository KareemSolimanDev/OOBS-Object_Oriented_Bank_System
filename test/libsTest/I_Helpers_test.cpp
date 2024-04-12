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
//============"isIntInRange() function Test"===========
void isIntInRange_Test()
{
    Ktest isIntInRange_Test("isIntInRange() function Test");
    isIntInRange_Test.EXPECT_TRUE(Input_helpers::isIntInRange(15,1,100));
    isIntInRange_Test.EXPECT_FALSE(Input_helpers::isIntInRange(110,1,100));// 110 out of range(1:100)!
    isIntInRange_Test.DISPLAY_DATA();
}
//==================================================


int main()
{

    readInt_Test();
    readStr_Test();
    isIntInRange_Test();

    return 0;
}

