#pragma once
#include "screens/Login/Login.h"
#include "screens/Dashboard/Dashboard.h"
#include "Config.h"

namespace App
{
    void run(bool testingCase=false)
    {
        
        while (Config::AppRuningStatus)
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
