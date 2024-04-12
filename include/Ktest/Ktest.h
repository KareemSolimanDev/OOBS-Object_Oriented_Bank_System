#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


using std::string;
using std::vector;

struct testData{
    string name;
    short  testsCount;
    short  errorCount;
    string report;

    void DISPLAY_DATA();
};



class Ktest
{
private:
    string _name;
    short  _testsCount;
    short  _errorCount;
    string _report;

    
    template <typename T>
    static string _toString(T data);

    static string _toString(string str);
public:
    Ktest(string name);
    

    testData GET_DATA();
    void DISPLAY_DATA();

// ======================================================
// ======================================================



    template <typename T>
    static bool S_EXPECT_EQ(T acctual,T expected);

    template <typename T>
    void EXPECT_EQ(T acctual,T expected,bool report=true);

    template <typename T>
    static bool S_EXPECT_EQ(vector<T> acctual_container ,vector<T> expected_container);

    template <typename T>
    void EXPECT_EQ(vector<T> acctual_container ,vector<T> expected_container,bool report=true);

    template <typename T>
    static bool S_EXPECT_NE(T acctual,T expected);
    
    template <typename T>
    void EXPECT_NE(T acctual,T expected,bool report=true);

    template <typename T>
    static bool S_EXPECT_LT(T acctual,T expected);

    template <typename T>
    void EXPECT_LT(T acctual,T expected,bool report=true);

    template <typename T>
    static bool S_EXPECT_GT(T acctual,T expected);

    template <typename T>
    void EXPECT_GT(T acctual,T expected,bool report=true);


    template <typename T>
    static bool S_EXPECT_LE(T acctual,T expected);

    template <typename T>
    void EXPECT_LE(T acctual,T expected,bool report=true);

    template <typename T>
    static bool S_EXPECT_GE(T acctual,T expected);

    template <typename T>
    void EXPECT_GE(T acctual,T expected,bool report=true);



    static bool S_EXPECT_TRUE(bool condition);

    void EXPECT_TRUE(bool condition,bool report=true);

    static bool S_EXPECT_FALSE(bool condition);
    
    void EXPECT_FALSE(bool condition,bool report=true);

// ======================================================
// ======================================================

    template <typename T>
    static vector<short> S_SUITE_EQ(vector<T> acctual,vector<T> expected);

    template <typename T>
    void SUITE_EQ(vector<T> acctual,vector<T> expected,bool report=true);


    template <typename T>
    static vector<short> S_SUITE_NE(vector<T> acctual,vector<T> expected);

    template <typename T>
    void SUITE_NE(vector<T> acctual,vector<T> expected,bool report=true);

    template <typename T>
    static vector<short> S_SUITE_LT(vector<T> acctual,vector<T> expected);

    template <typename T>
    void SUITE_LT(vector<T> acctual,vector<T> expected,bool report=true);

    template <typename T>
    static vector<short> S_SUITE_GT(vector<T> acctual,vector<T> expected);

    template <typename T>
    void SUITE_GT(vector<T> acctual,vector<T> expected,bool report=true);

    template <typename T>
    static vector<short> S_SUITE_LE(vector<T> acctual,vector<T> expected);

    template <typename T>
    void SUITE_LE(vector<T> acctual,vector<T> expected,bool report=true);


    template <typename T>
    static vector<short> S_SUITE_GE(vector<T> acctual,vector<T> expected);

    template <typename T>
    void SUITE_GE(vector<T> acctual,vector<T> expected,bool report=true);

    template <typename T>
    static vector<short> S_SUITE_TRUE(vector<T> conditions);

    template <typename T>
    void SUITE_TRUE(vector<T> conditions,bool report=true);


    template <typename T>
    static vector<short> S_SUITE_FALSE(vector<T> conditions);

    template <typename T>
    void SUITE_FALSE(vector<T> conditions,bool report=true);


// ======================================================
// ======================================================



    template <typename T>
    static string S_MAKE_REPORT(vector<T> acctual,vector<T> expected,vector<short> fails);


    template <typename T,typename... Args>
    static string S_HAVE_ERROR(T (*func)(Args...), Args... args);
    
    template <typename T,typename... Args>
    void HAVE_ERROR(T (*func)(Args...), Args... args);

    template <typename T,typename J>
    static vector<T> S_GET_ACCTUAL(vector<J> inputs,T (*func)(J));


    template <typename T,typename... Args>
    T INSERT_INPUT(string input,T (*func)(Args...), Args... args);


    template <typename... Args>
    string CAPTURE_OUTPUT(void (*func)(Args...),Args... args);

    static string GET_F_CONTENT(const std::string filePath);
};

// include template functions defenition
#include "Ktest.cpp"

