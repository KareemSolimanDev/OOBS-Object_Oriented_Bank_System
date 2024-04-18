#include "Bank.h"

vector<string> Bank::loadAdminsData()
{
    return File_helpers::GetDataFromFile(Path::Admins_F);
}