# [**(OOBS)** -> Object Oriented Bank System.](../../README.md)

## 🧪 Project Testing.

### 📝 Notes
1. this is not actuall testing process, it's only to visualize the testing step
2. as it not actuall test process so i donot use testing framework i **built one** called ("**Ktest** => Kareem test" like Gtest => Google test) 
3. Ktest has main functions common in testing (built on OOP)
4. i donot test all function i test libs functions , and another functtions manually tested.


### ⏹ How use Ktest
    Ktest has the common functions for testing and some functions for mocking.
    let's assume we want to test Trim() function
```cpp
//                      test Trim function

// make void function has Trim with "_Test" as suffix.
void Trim_Test()
{
    // create object from Ktest class .
    // pass title of test as an argument to constructor.
    Ktest Trim_Test("Trim() function Test");

    // declare string variable to store output of Trim().
    // pass your test case input.
    string output=DataManip_helpers::Trim("      Kareem.       ");

    // use EXPECT_EQ() to check if output equal what you expected.
    // pass output, expected_output as arguments.
    Trim_Test.EXPECT_EQ(output,(string)"Kareem.");

    // add another test cases here.
    // like above .......
    
    // no your object stored the result of all your test cases.
    // display result by DISPLAY_DATA().
    Trim_Test.DISPLAY_DATA();
}

// and of course, call Trim_Test().

//==================================================
```
#### output will look like this if test pass:

    =================================
    Test Name : Trim() function Test
    Tests Count : 1
    Test Status : Passed!
    =================================

#### else:
> Report will show you exactly where is the error;

    =================================
    Test Name : Trim() function Test
    Tests Count : 1
    Test Status : Failed!
    Errors Count : 1
    Report :
    1- Error in Test [ 1 : EXPECT_EQ ] :: ( Should be : [Kareem.] ,But it : Kareem ) !

    =================================

<hr>
