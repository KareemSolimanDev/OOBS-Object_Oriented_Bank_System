#include "Ui_helpers.h"

//======================================================================
//==================        UI manips             ======================
//======================================================================

void Ui_helpers::clear()
    {
        system("cls");
    }

//======================================================================
//==================        Components            ======================
//======================================================================

void Ui_helpers::alert(string msg,char lineSign, short Xpadding, short Ypadding)
{
    short width = (msg.length()) + (Xpadding * 2);
    std::cout << output_helpers::repeat(lineSign, width) << output_helpers::repeat('\n', Ypadding);
    std::cout << output_helpers::repeat(' ', Xpadding) << msg << output_helpers::repeat('\n', Ypadding);
    std::cout << output_helpers::repeat(lineSign, width) << std::endl;
}

void Ui_helpers::warning(string title)
{
    alert(title,'!',20);
}

void Ui_helpers::header(string title)
{
    alert(title,'#',20,2);
}

void Ui_helpers::menu(string menuTitle, vector<string> menuItems,short leftMargin)
{
    short Lmargin = leftMargin;

    if (leftMargin==-1)
    {
        Lmargin = menuTitle.length() + 1;
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

int Ui_helpers::intField(string label,int min, int max ,string errorMsg)
{
    long long num = 0;
    bool error = false;

    do {
        std::cout << label;
        num=Input_helpers::readInt();
        error = !Input_helpers::isNumInRange(num,(long long)min,(long long)max);

        if (error) {
            std::cout << errorMsg << std::endl;
        }
    } while (error);

    return num;
}

float Ui_helpers::floatField(string label,float min, float max ,string errorMsg)
{
    double num = 0;
    bool error = false;

    do {
        std::cout << label;
        num=Input_helpers::readFloat();
        error = !Input_helpers::isNumInRange(num,(double)min,(double)max);

        if (error) {
            std::cout << errorMsg << std::endl;
        }
    } while (error);

    return num;
}

string Ui_helpers::textField(string label)
{
    string stringInput;
    std::cout << label;
    stringInput = Input_helpers::readStr();
    return stringInput;
}

bool Ui_helpers::confirmField(string label, vector<string> passCases)
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

short Ui_helpers::selectField(short menuSize,string label,string errorMsg)
{
    short answer=intField(label,1,menuSize,errorMsg);
    return answer;
}

