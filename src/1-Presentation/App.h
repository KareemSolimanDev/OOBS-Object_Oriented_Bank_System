#pragma once
#include "screens/Login/Login.h"
#include "screens/Dashboard/Dashboard.h"
#include "Config.h"

namespace App
{
    void run(bool testingCase=false)
    {
        if (testingCase)
        {
            DashboardScreen.render();

        }else{
            while (Config::AppRuningStatus)
            {
                LoginScreen.render();
            }

        }
        
    }
} // namespace App
