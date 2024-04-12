#include "Ktest.h"

void testData::DISPLAY_DATA()
{
    std::cout << "=================================\n";
    std::cout << "Test Name : " << name << "\n";
    std::cout << "Tests Count : " << testsCount << "\n";
    if (errorCount)
    {
        std::cout << "Test Status : Failed!\n";
        std::cout << "Errors Count : " << errorCount << "\n";
        std::cout << "Report :\n" << report << "\n";
    }else{
        std::cout << "Test Status : Passed!\n";
    }
    std::cout << "=================================" << std::endl;
}


template <typename T>
std::string Ktest::_toString(T data) {
    std::stringstream ss;
    ss << data;
    return ss.str();
}

std::string Ktest::_toString(std::string str) {
    return str;
}



Ktest::Ktest(std::string name) : _name(name),_testsCount(0),_errorCount(0),_report(""){}

testData Ktest::GET_DATA()
{
    return {_name,_testsCount,_errorCount,_report};
}
void Ktest::DISPLAY_DATA()
{
    GET_DATA().DISPLAY_DATA();
    
}

// ======================================================
// ======================================================



template <typename T>
bool Ktest::S_EXPECT_EQ(T acctual,T expected)
{
    if (acctual != expected)
    {
        return false;
    }
    return true;
}

template <typename T>
void Ktest::EXPECT_EQ(T acctual,T expected,bool report)
{
    _testsCount++;
    if (S_EXPECT_EQ(acctual,expected)==false)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_EQ ] :: ( Should be : [" + _toString(expected) + "] ,But it : " + _toString(acctual) + " ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_EQ ] => not reported!! \n";
        }
        
    }
}

template <typename T>
bool Ktest::S_EXPECT_EQ(vector<T> acctual_container ,vector<T> expected_container)
{
    if (acctual_container.size()!=expected_container.size())
    {

        return false;
    }

    for (short i = 0; i < acctual_container.size(); i++)
    {
        if (acctual_container[i]!=expected_container[i])
        {

            return false;
        }
    }
    
    return true;
}

template <typename T>
void Ktest::EXPECT_EQ(vector<T> acctual_container ,vector<T> expected_container,bool report)
{
    _testsCount++;
    if (S_EXPECT_EQ(acctual_container,expected_container)==false)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_EQ ] :: ( containers not equal ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_EQ ] => not reported!! \n";
        }
        
    }
}

template <typename T>
bool Ktest::S_EXPECT_NE(T acctual,T expected)
{
    if (acctual == expected)
    {
        return false;
    }
    return true;
}

template <typename T>
void Ktest::EXPECT_NE(T acctual,T expected,bool report)
{
    _testsCount++;
    if (S_EXPECT_NE(acctual,expected)==false)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_NE ] :: ( Shouldn't be : [" + _toString(expected) + "] ,But it : " + _toString(acctual) + " ) !\n");
        }else
        {
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_NE ] => not reported!! \n";
        }
        
    }
}

template <typename T>
bool Ktest::S_EXPECT_LT(T acctual,T expected)
{
    if (acctual >= expected)
    {
        return false;
    }
    return true;
}

template <typename T>
void Ktest::EXPECT_LT(T acctual,T expected,bool report)
{
    _testsCount++;
    if (S_EXPECT_LT(acctual,expected)==false)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_LT ] :: ( Should be less than : [" + _toString(expected) + "] ,But it : " + _toString(acctual) + " ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_LT ] => not reported!! \n";
        }
        
    }
}

template <typename T>
bool Ktest::S_EXPECT_GT(T acctual,T expected)
{
    if (acctual <= expected)
    {
        return false;
    }
    return true;
}

template <typename T>
void Ktest::EXPECT_GT(T acctual,T expected,bool report)
{
    _testsCount++;
    if (S_EXPECT_GT(acctual,expected)==false)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_GT ] :: ( Should be greater than : [" + _toString(expected) + "] ,But it : " + _toString(acctual) + " ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_GT ] => not reported!! \n";
        }
        
    }
}


template <typename T>
bool Ktest::S_EXPECT_LE(T acctual,T expected)
{
    if (acctual > expected)
    {
        return false;
    }
    return true;
}

template <typename T>
void Ktest::EXPECT_LE(T acctual,T expected,bool report)
{
    _testsCount++;
    if (S_EXPECT_LE(acctual,expected)==false)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_LE ] :: ( Should be equal or less than : [" + _toString(expected) + "] ,But it : " + _toString(acctual) + " ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_LE ] => not reported!! \n";
        }
        
    }
}


template <typename T>
bool Ktest::S_EXPECT_GE(T acctual,T expected)
{
    if (acctual < expected)
    {
        return false;
    }
    return true;
}

template <typename T>
void Ktest::EXPECT_GE(T acctual,T expected,bool report)
{
    _testsCount++;
    if (S_EXPECT_GE(acctual,expected)==false)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_GE ] :: ( Should be equal or greater than : [" + _toString(expected) + "] ,But it : " + _toString(acctual) + " ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_GE ] => not reported!! \n";
        }
        
    }
}



bool Ktest::S_EXPECT_TRUE(bool condition)
{
    return (condition==true);
}

void Ktest::EXPECT_TRUE(bool condition,bool report)
{
    _testsCount++;
    if (S_EXPECT_TRUE(condition)==false)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_TRUE ] :: ( Should be : true ,But it : false ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_TRUE ] => not reported!! \n";
        }
        
    }
}

bool Ktest::S_EXPECT_FALSE(bool condition)
{
    return (condition==false);
}

void Ktest::EXPECT_FALSE(bool condition,bool report)
{
    _testsCount++;
    if (S_EXPECT_FALSE(condition)==false)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_FALSE ] :: ( Should be : false ,But it : true ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : EXPECT_FALSE ] => not reported!! \n";
        }
        
    }
}

// ======================================================
// ======================================================

template <typename T>
vector<short> Ktest::S_SUITE_EQ(vector<T> acctual,vector<T> expected)
{
    vector<short> failCases;
    for (short i = 0; i < acctual.size(); i++)
    {
        if (!S_EXPECT_EQ(acctual[i],expected[i]))
        {
            failCases.push_back(i);
        }
    }
    return failCases;
}

template <typename T>
void Ktest::SUITE_EQ(vector<T> acctual,vector<T> expected,bool report)
{
    _testsCount++;
    vector<short> failCases=S_SUITE_EQ(acctual,expected);
    for (short i = 0; i < failCases.size(); i++)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_EQ - Case("+_toString(failCases[i]+1)+") ] :: ( Should be : [" + _toString(expected[failCases[i]]) + "] ,But it : " + _toString(acctual[failCases[i]]) + " ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_EQ : Case("+_toString(failCases[i]+1)+") ] => not reported!! \n";
        }
    }
}


template <typename T>
vector<short> Ktest::S_SUITE_NE(vector<T> acctual,vector<T> expected)
{
    vector<short> failCases;
    for (short i = 0; i < acctual.size(); i++)
    {
        if (!S_EXPECT_NE(acctual[i],expected[i]))
        {
            failCases.push_back(i);
        }
    }
    return failCases;
}

template <typename T>
void Ktest::SUITE_NE(vector<T> acctual,vector<T> expected,bool report)
{
    _testsCount++;
    vector<short> failCases=S_SUITE_NE(acctual,expected);
    for (short i = 0; i < failCases.size(); i++)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_NE - Case("+_toString(failCases[i]+1)+") ] :: ( Shouldn't be : [" + _toString(expected[failCases[i]]) + "] ,But it : " + _toString(acctual[failCases[i]]) + " ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_NE : Case("+_toString(failCases[i]+1)+") ] => not reported!! \n";
        }
    }
}

template <typename T>
vector<short> Ktest::S_SUITE_LT(vector<T> acctual,vector<T> expected)
{
    vector<short> failCases;
    for (short i = 0; i < acctual.size(); i++)
    {
        if (!S_EXPECT_LT(acctual[i],expected[i]))
        {
            failCases.push_back(i);
        }
    }
    return failCases;
}

template <typename T>
void Ktest::SUITE_LT(vector<T> acctual,vector<T> expected,bool report)
{
    _testsCount++;
    vector<short> failCases=S_SUITE_LT(acctual,expected);
    for (short i = 0; i < failCases.size(); i++)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_LT - Case("+_toString(failCases[i]+1)+") ] :: ( Should be less than : [" + _toString(expected[failCases[i]]) + "] ,But it : " + _toString(acctual[failCases[i]]) + " ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_LT : Case("+_toString(failCases[i]+1)+") ] => not reported!! \n";
        }
    }
}

template <typename T>
vector<short> Ktest::S_SUITE_GT(vector<T> acctual,vector<T> expected)
{
    vector<short> failCases;
    for (short i = 0; i < acctual.size(); i++)
    {
        if (!S_EXPECT_GT(acctual[i],expected[i]))
        {
            failCases.push_back(i);
        }
    }
    return failCases;
}

template <typename T>
void Ktest::SUITE_GT(vector<T> acctual,vector<T> expected,bool report)
{
    _testsCount++;
    vector<short> failCases=S_SUITE_GT(acctual,expected);
    for (short i = 0; i < failCases.size(); i++)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_GT - Case("+_toString(failCases[i]+1)+") ] :: ( Should be greater than : [" + _toString(expected[failCases[i]]) + "] ,But it : " + _toString(acctual[failCases[i]]) + " ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_GT : Case("+_toString(failCases[i]+1)+") ] => not reported!! \n";
        }
    }
}

template <typename T>
vector<short> Ktest::S_SUITE_LE(vector<T> acctual,vector<T> expected)
{
    vector<short> failCases;
    for (short i = 0; i < acctual.size(); i++)
    {
        if (!S_EXPECT_LR(acctual[i],expected[i]))
        {
            failCases.push_back(i);
        }
    }
    return failCases;
}

template <typename T>
void Ktest::SUITE_LE(vector<T> acctual,vector<T> expected,bool report)
{
    _testsCount++;
    vector<short> failCases=S_SUITE_LE(acctual,expected);
    for (short i = 0; i < failCases.size(); i++)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_LE - Case("+_toString(failCases[i]+1)+") ] :: ( Should be equal or less than : [" + _toString(expected[failCases[i]]) + "] ,But it : " + _toString(acctual[failCases[i]]) + " ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_LE : Case("+_toString(failCases[i]+1)+") ] => not reported!! \n";
        }
    }
}

template <typename T>
vector<short> Ktest::S_SUITE_GE(vector<T> acctual,vector<T> expected)
{
    vector<short> failCases;
    for (short i = 0; i < acctual.size(); i++)
    {
        if (!S_EXPECT_GE(acctual[i],expected[i]))
        {
            failCases.push_back(i);
        }
    }
    return failCases;
}

template <typename T>
void Ktest::SUITE_GE(vector<T> acctual,vector<T> expected,bool report)
{
    _testsCount++;
    vector<short> failCases=S_SUITE_GE(acctual,expected);
    for (short i = 0; i < failCases.size(); i++)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_GE - Case("+_toString(failCases[i]+1)+") ] :: ( Should be equal or greater than : [" + _toString(expected[failCases[i]]) + "] ,But it : " + _toString(acctual[failCases[i]]) + " ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_GE : Case("+_toString(failCases[i]+1)+") ] => not reported!! \n";
        }
    }
}

template <typename T>
vector<short> Ktest::S_SUITE_TRUE(vector<T> conditions)
{
    vector<short> failCases;
    for (short i = 0; i < conditions.size(); i++)
    {
        if (!S_EXPECT_TRUE(conditions[i]))
        {
            failCases.push_back(i);
        }
    }
    return failCases;
}

template <typename T>
void Ktest::SUITE_TRUE(vector<T> conditions,bool report)
{
    _testsCount++;
    vector<short> failCases=S_SUITE_TRUE(conditions);
    for (short i = 0; i < failCases.size(); i++)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_TRUE - Case("+_toString(failCases[i]+1)+") ] :: ( Should be : true ,But it : false ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_TRUE : Case("+_toString(failCases[i]+1)+") ] => not reported!! \n";
        }
    }
}


template <typename T>
vector<short> Ktest::S_SUITE_FALSE(vector<T> conditions)
{
    vector<short> failCases;
    for (short i = 0; i < conditions.size(); i++)
    {
        if (!S_EXPECT_FALSE(conditions[i]))
        {
            failCases.push_back(i);
        }
    }
    return failCases;
}

template <typename T>
void Ktest::SUITE_FALSE(vector<T> conditions,bool report)
{
    _testsCount++;
    vector<short> failCases=S_SUITE_FALSE(conditions);
    for (short i = 0; i < failCases.size(); i++)
    {
        _errorCount++;
        if (report)
        {
            _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_FALSE - Case("+_toString(failCases[i]+1)+") ] :: ( Should be : false ,But it : true ) !\n");
        }else{
            _report+=_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : SUITE_FALSE : Case("+_toString(failCases[i]+1)+") ] => not reported!! \n";
        }
    }
}


// ======================================================
// ======================================================



template <typename T>
std::string Ktest::S_MAKE_REPORT(vector<T> acctual,vector<T> expected,vector<short> fails)
{
    std::string report;

    for (short i = 0; i < fails.size(); i++)
    {
        report+="Test case : " + _toString(fails[i]) + " ,Should be : " + _toString(expected[fails[i]]) + " ,But it : " + _toString(acctual[fails[i]]) + "\n";
    }
    

    return report;
}


template <typename T,typename... Args>
std::string Ktest::S_HAVE_ERROR(T (*func)(Args...), Args... args)
{
    try
    {
        func(std::forward<Args>(args)...);
    }
    catch(const std::exception& e)
    {
        return e.what();
    }
    
    return "";
}

template <typename T,typename... Args>
void Ktest::HAVE_ERROR(T (*func)(Args...), Args... args)
{
    _testsCount++;
    
    std::string errorMsg=S_HAVE_ERROR(func,std::forward<Args>(args)...);
    if(errorMsg != "")
    {
        _errorCount++;
        _report+=(_toString(_errorCount)+"- Error in Test [ "+_toString(_testsCount)+" : HAVE_ERROR ] :: ( "+ errorMsg + " ) !\n");

    }
}

template <typename T,typename J>
vector<T> Ktest::S_GET_ACCTUAL(vector<J> inputs,T (*func)(J))
{
    vector<T> acctuals;

    for (J input : inputs)
    {
        acctuals.push_back(func(input));
    }
    return acctuals;
}


template <typename T,typename... Args>
T Ktest::INSERT_INPUT(std::string input,T (*func)(Args...), Args... args) {

    std::stringstream input_stream(input);

    std::streambuf* orig_cin = std::cin.rdbuf(input_stream.rdbuf());

    T result = func(std::forward<Args>(args)...);

    std::cin.rdbuf(orig_cin);
    
    return result;
}


template <typename... Args>
std::string Ktest::CAPTURE_OUTPUT(void (*func)(Args...),Args... args)
{
    std::stringstream output_stream;

    std::streambuf* orig_cout = std::cout.rdbuf(output_stream.rdbuf());

    func(std::forward<Args>(args)...);

    std::cout.rdbuf(orig_cout);
    return output_stream.str();
}

std::string Ktest::GET_F_CONTENT(const std::string filePath)
{
    std::ifstream file(filePath);
    std::string content;

    std::string line;
    while (std::getline(file, line)) {
        content += line + "\n";
    }
    file.close();

    return content;
}