#include <string>

#include "../../include/Ktest/Ktest.h"
#include "../../include/libs/F_Helpers/File_helpers.h"

using std::string;

const string fName="temp_file.txt";

//==================================================
//======="AppendDataToFile() function Test"=========
void AppendDataToFile_Test()
{
    Ktest AppendDataToFile_Test("AppendDataToFile() function Test");

    File_helpers::AppendDataToFile(fName,"1-test");
    string fileContent=AppendDataToFile_Test.GET_F_CONTENT(fName);

    AppendDataToFile_Test.EXPECT_EQ(fileContent,(string)"1-test\n");

    File_helpers::AppendDataToFile(fName,"2-test");
    fileContent=AppendDataToFile_Test.GET_F_CONTENT(fName);

    AppendDataToFile_Test.EXPECT_EQ(fileContent,(string)"1-test\n2-test\n");
    
    AppendDataToFile_Test.DISPLAY_DATA();
}
//==================================================

//==================================================
//======="WriteDataOnFile() function Test"=========
void WriteDataOnFile_Test()
{
    Ktest WriteDataOnFile_Test("WriteDataOnFile() function Test");

    File_helpers::WriteDataOnFile(fName,{"1-test"});
    string fileContent=WriteDataOnFile_Test.GET_F_CONTENT(fName);

    WriteDataOnFile_Test.EXPECT_EQ(fileContent,(string)"1-test\n");

    File_helpers::WriteDataOnFile(fName,{"2-test","3-test"});
    fileContent=WriteDataOnFile_Test.GET_F_CONTENT(fName);

    WriteDataOnFile_Test.EXPECT_EQ(fileContent,(string)"2-test\n3-test\n");
    
    WriteDataOnFile_Test.DISPLAY_DATA();
}
//==================================================

//==================================================
//======="GetDataFromFile() function Test"=========
void GetDataFromFile_Test()
{
    Ktest GetDataFromFile_Test("GetDataFromFile() function Test");

    vector<string> Data=File_helpers::GetDataFromFile(fName);

    GetDataFromFile_Test.EXPECT_EQ(Data[0],(string)"2-test");

    GetDataFromFile_Test.EXPECT_EQ(Data[1],(string)"3-test");
    
    GetDataFromFile_Test.DISPLAY_DATA();
}
//==================================================

int main()
{

    AppendDataToFile_Test();
    WriteDataOnFile_Test();
    GetDataFromFile_Test();

    return 0;
}