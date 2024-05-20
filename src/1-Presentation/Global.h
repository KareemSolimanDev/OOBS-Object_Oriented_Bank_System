#pragma once
#include "../2-Business/Admin/Admin.h"

namespace Global
{
    bool AppRuningStatus=true;

    enum AdminPermissions
    {
        AllP=-1,
        ShowClientListP = 1,
        ClientsOpsP = 2,
        TransactionsP = 4,
        AdminsOpsP = 8,
        LogsP = 16,
    };
    
} // namespace Global
