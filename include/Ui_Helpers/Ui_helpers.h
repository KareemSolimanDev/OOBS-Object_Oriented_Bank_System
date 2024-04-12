#pragma once
#include <iostream>
#include "libs/I_Helpers/Input_helpers.h"
#include "libs/O_Helpers/output_helpers.h"
#include <vector>

using std::string;
using std::vector;



class Ui_helpers
{
public:


    //======================================================================
    //==================        Components            ======================
    //======================================================================

    static void alert(string msg,char lineSign, short Xpadding, short Ypadding);
    
    static void header(string title);

    static void menu(string menuTitle, vector<string> menuItems,short leftMargin);
    
    //======================================================================
    //====================        Fields            ========================
    //======================================================================

    static int intField(string label,int min = INT_MIN, int max ,string errorMsg);
    static string textField(string label);

    static bool confirmField(string label, vector<string> passCases);

    static short selectField(string label,short menuSize,string errorMsg);

};

#include "Ui_helpers.cpp"