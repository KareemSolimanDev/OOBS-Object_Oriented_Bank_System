#pragma once
#include "screens/Login/Login.h"
#include "screens/Dashboard/Dashboard.h"
#include "Global.h"

namespace App
{
    void run(bool testingCase=false)
    {
        
        while (Global::AppRuningStatus)
        {
            if (testingCase)
            {
                DashboardScreen.render();
            }else{
                LoginScreen.render();

            }
        }
        
    }
} // namespace App
