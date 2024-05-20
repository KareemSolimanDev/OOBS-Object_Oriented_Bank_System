#include "Ui_helpers.h"

//======================================================================
//==================        UI manips             ======================
//======================================================================

void Ui_helpers::clear()
{
    system("cls");
}

void Ui_helpers::pause(string msg)
{
    if(msg!="")
        std::cout << msg+", ";
    system("pause");
}

//======================================================================
//==================        Components            ======================
//======================================================================

void Ui_helpers::alert(string msg,char lineSign, short Xpadding, short Ypadding)
{
    if(msg!="")
    {
        short width = (msg.length()) + (Xpadding * 2);
        std::cout << output_helpers::repeat(lineSign, width) << output_helpers::repeat('\n', Ypadding);
        std::cout << output_helpers::repeat(' ', Xpadding) << msg << output_helpers::repeat('\n', Ypadding);
        std::cout << output_helpers::repeat(lineSign, width) << std::endl;
    }
}

void Ui_helpers::warning(string title)
{
    alert(title,'!',20);
}

void Ui_helpers::error(string title)
{
    alert(title,'X',20);
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

void Ui_helpers::tabel(string title,vector<string> header,vector<vector<string>> data,short tabelWidth)
{
    tabelWidth = tabelWidth < minTabelWidth ? minTabelWidth : tabelWidth;

    std::cout << output_helpers::repeat(" ",((tabelWidth/2)-(title.length()/2))) << title << "\n";

    std::cout << output_helpers::repeat("_",tabelWidth) << "\n";
    for (string &cellName : header)
    {
        std::cout << "| " << std::left << std::setw(tabelWidth/(header.size()+1)) << cellName ;
    }
    std::cout << "\n";
    std::cout << output_helpers::repeat("_",tabelWidth) << "\n";
    for (vector<string> &line : data)
    {
        for (string &info : line)
        {
            std::cout << "| " << std::setw(tabelWidth/(header.size()+1)) << std::left << info;
        }
            std::cout << "\n";
    }
    std::cout << output_helpers::repeat("_",tabelWidth) << std::endl;
}

void Ui_helpers::card(string title,vector<string> keys,vector<string> names,short cardWidth)
{
        short keysColumnWidth=cardWidth/4;

        if (title!="")
            {alert(title);}

        std::cout << output_helpers::repeat('=',cardWidth) <<"\n";
        for (short i=0; i < keys.size();i++)
        {                  // manage width of keys column in card
            std::cout   << (keys[i]+output_helpers::repeat(' ',keysColumnWidth-keys[i].length()) + ": ") 
                        << names[i] << "\n";
            
        }
        std::cout << output_helpers::repeat('=',cardWidth) << std::endl;
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

