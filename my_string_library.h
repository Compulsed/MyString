#ifndef _MY_STRING_LIBRARY_H_
#define _MY_STRING_LIBRARY_H_

#include <iostream>
#include <stdlib.h>
#include <stdexcept>

const bool debug = true;

class MyString{
private:
    char* cstring;
    int string_length; // Not including null terminator 'abc' == 3 but stores as 4
public:
    // Copies the string
    MyString(char* sent_cstring);
    MyString(char* sent_cstring1, char* sent_cstring2);
    MyString(char* sent_cstring, int desired_length);   // Takes a cstring and cuts the length
    MyString();
    ~MyString();

    // Returns the location of the null terminator
    char* last();
    char* first();

    char* get_cstring();
    int length();
    MyString sub_string(int start, int end);

    char operator[](int i);
    bool operator==(MyString& lhs_string);
    MyString operator+(MyString& lhs_string);
    MyString& operator+=(MyString& lhs_string);
    MyString& operator=(MyString& lhs_string);

    friend std::ostream& operator<<(std::ostream& output, MyString& string);
};

#endif