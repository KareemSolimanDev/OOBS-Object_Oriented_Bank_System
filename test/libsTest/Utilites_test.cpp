#include <string>

#include "../../include/Ktest/Ktest.h"
#include "../../include/libs/Utilities/Utilities.h"

using std::string;

//==================================================
//============="getCurrentDateTime() function Test"============
void getCurrentDateTime_Test()
{
    Ktest getCurrentDateTime_Test("getCurrentDateTime() function Test");
    getCurrentDateTime_Test.EXPECT_EQ(Date::getCurrentDateTime().year,string("2024"));//my current date
    getCurrentDateTime_Test.EXPECT_EQ(Date::getCurrentDateTime().month,string("4"));
    getCurrentDateTime_Test.EXPECT_EQ(Date::getCurrentDateTime().day,string("22"));
    getCurrentDateTime_Test.EXPECT_EQ(Date::getCurrentDateTime().hour,string("6"));
    getCurrentDateTime_Test.EXPECT_EQ(Date::getCurrentDateTime().minute,string("40"));//this matched with first test
    getCurrentDateTime_Test.EXPECT_LE(stoi(Date::getCurrentDateTime().second),40);
    getCurrentDateTime_Test.DISPLAY_DATA();
}
//==================================================


int main()
{

    getCurrentDateTime_Test();

    return 0;
}