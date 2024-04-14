#pragma once
#include <iostream>
#include "../../../include/Ui_Helpers/Ui_helpers.h"


using std::string;
using std::cout;

class BaseScreen
{
protected:

    void __outScreenHeader(string title)
    {
        Ui_helpers::header(title);
    }

    virtual void show() = 0;

};

