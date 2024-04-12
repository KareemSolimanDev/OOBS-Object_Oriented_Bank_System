#include "Ui_helpers.h"

//======================================================================
//==================        Components            ======================
//======================================================================

void Ui_helpers::alert(string msg="Welcome here.",char lineSign='=', short Xpadding = 15, short Ypadding = 1)
{
    short width = (msg.length()) + (Xpadding * 2);
    std::cout << output_helpers::repeat(lineSign, width) << output_helpers::repeat('\n', Ypadding);
    std::cout << output_helpers::repeat(' ', Xpadding) << msg << output_helpers::repeat('\n', Ypadding);
    std::cout << output_helpers::repeat(lineSign, width) << std::endl;
}

void Ui_helpers::header(string title)
{
    alert(title,'#',20,2);
}

void Ui_helpers::menu(string menuTitle= "Menu", vector<string> menuItems={},short leftMargin=-1)
{
    short Lmargin = leftMargin;

    if (leftMargin==-1)
    {
        Lmargin = menuTitle.length() + 2;
    }
    
    if(menuTitle != "")
    {
        std::cout << menuTitle << " :\n";
    }

    for (short i = 0; i < menuItems.size(); i++)
    {
        std::cout << output_helpers::repeat(' ', Lmargin) << '[' << i + 1 << ']' << " : " << menuItems[i] << '\n';
    }
    std::cout << output_helpers::repeat('=', 60) << std::endl;
}

//======================================================================
//====================        Fields            ========================
//======================================================================

int Ui_helpers::intField(string label="Please enter a number : \n",int min = INT_MIN, int max = INT_MAX,string errorMsg="Number out of range!\n") {
    long long num = 0;
    bool error = false;

    do {
        std::cout << label;
        num=Input_helpers::readInt();
        error = !Input_helpers::isIntInRange(num,min,max);

        if (error) {
            std::cout << errorMsg << std::endl;
        }
    } while (error);

    return num;
}

string Ui_helpers::textField(string label="Please enter a text : \n")
{
    string stringInput;
    std::cout << label;
    stringInput = Input_helpers::readStr();
    return stringInput;
}

bool Ui_helpers::confirmField(string label="Do you agree (Y/N): \n", vector<string> passCases={"y","Y"})
{
    string answer=textField(label);

    for (string passCase : passCases)
    {
        if (answer == passCase)
        {
            return true;
        }
        
    }
    return false;
}

short Ui_helpers::selectField(string label="Select choice : \n",short menuSize=0,string errorMsg="inValid choice => select another one.\n")
{
    short answer=intField(label,1,menuSize,errorMsg);
    return answer;
}

