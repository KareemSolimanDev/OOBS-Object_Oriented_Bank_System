#pragma once
#include <iostream>
#include "../libs/I_Helpers/Input_helpers.h"
#include "../libs/O_Helpers/output_helpers.h"
#include <vector>
#include <iomanip>

using std::string;
using std::vector;



class Ui_helpers
{
private:
    static const short minTabelWidth= 90;
    static const short minCardWidth= 60;
public:


    //======================================================================
    //==================        UI manips             ======================
    //======================================================================
    
    static void clear();

    static void pause(string msg="");

    //======================================================================
    //==================        Components            ======================
    //======================================================================

    static void alert(string msg="Welcome here.",char lineSign='=', short Xpadding = 15, short Ypadding = 1);
    
    static void warning(string title);

    static void error(string title);

    static void header(string title);

    static void menu(string menuTitle= "Menu", vector<string> menuItems={},short leftMargin=-1);

    static void tabel(string title,vector<string> header,vector<vector<string>> data,short tabelWidth=minTabelWidth);
    
    static void card(string title,vector<string> keys,vector<string> names,short cardWidth=minCardWidth);
    //======================================================================
    //====================        Fields            ========================
    //======================================================================

    static int intField(string label="Please enter a number : \n",int min = INT_MIN, int max = INT_MAX,string errorMsg="Number out of range!\n");

    static float floatField(string label="Please enter a number : \n",float min = __FLT_MIN__, float max = __FLT_MAX__,string errorMsg="Number out of range!\n");

    static string textField(string label="Please enter a text : \n");

    static bool confirmField(string label="Do you agree (Y/N): \n", vector<string> passCases={"y","Y"});

    static short selectField(short menuSize,string label="Select option : ",string errorMsg="!nValid choice, select another one.\n");

};

#include "Ui_helpers.cpp"