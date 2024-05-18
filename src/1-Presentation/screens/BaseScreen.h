#pragma once
#include <string>
#include "../../../include/Ui_Helpers/Ui_helpers.h"


using std::string;



class BaseScreen
{
private:
    void __outScreenHeader(string title)
    {
        Ui_helpers::header(title);
    }
protected:
    string _title;
    virtual void displayContent() = 0;
    virtual void handelInput() = 0;

public:
    void render()
    {
        Ui_helpers::clear();
        __outScreenHeader(this->_title);
        displayContent();
        handelInput();
    }

};

