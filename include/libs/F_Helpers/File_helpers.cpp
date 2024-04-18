#include "File_helpers.h"

void File_helpers::AppendDataToFile(string fileName, string Data)
{
    std::fstream myFile;
    myFile.open(fileName, std::ios::app);
    myFile << Data << std::endl;
    myFile.close();
}


void File_helpers::WriteDataOnFile(string fileName, vector<string> newData)
{
    std::fstream File;
    File.open(fileName, std::ios::out);

    for (string &line : newData)
    {
        File << line << std::endl;
    }
    File.close();
}

vector<string> File_helpers::GetDataFromFile(string fileName)
{
    std::fstream File;
    string Data;
    vector<string> vData;
    File.open(fileName, std::ios::in);
    while (getline(File, Data))
    {
        vData.push_back(Data);
    }
    File.close();
    return vData;
}