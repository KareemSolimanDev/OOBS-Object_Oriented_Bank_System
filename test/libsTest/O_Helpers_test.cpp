#include <string>

#include "../../include/Ktest/Ktest.h"
#include "../../include/libs/O_Helpers/output_helpers.h"

using std::string;

//==================================================
//============="repeat() function Test"============
void repeat_Test()
{
    Ktest repeat_Test("repeat() function Test");
    repeat_Test.EXPECT_EQ(output_helpers::repeat('+'),(string)"++");
    repeat_Test.EXPECT_EQ(output_helpers::repeat('+',0),(string)"");
    repeat_Test.EXPECT_EQ(output_helpers::repeat('+',3),(string)"+++");
    repeat_Test.DISPLAY_DATA();
}
//==================================================


int main()
{

    repeat_Test();

    return 0;
}