#include "my_string_library.h"

std::ostream& operator<<(std::ostream& output, MyString& string){
    output << string.cstring;
    return output;
}

// Copies the string
MyString::MyString(char* sent_cstring){
    int length = 0;

    while (sent_cstring[length] != '\0'){
        ++length;
    }

    cstring = new char[length + 1]; // For null terminator

    for (int i = 0; i < length; ++i){
        cstring[i] = sent_cstring[i];
    }

    cstring[length] = '\0';
    string_length = length;
}

// Concatinates two cstrings together
MyString::MyString(char* sent_cstring1, char* sent_cstring2){
    int length1 = 0; // Length is all chars but the terminator
    int length2 = 0;

    while (sent_cstring1[length1] != '\0'){
        ++length1;
    }

    while (sent_cstring2[length2] != '\0'){
        ++length2;
    }

    cstring = new char[length1 + length2 + 1]; // For null terminator

    int i = 0;
    while (sent_cstring1[i] != '\0'){
        cstring[i] = sent_cstring1[i];
        ++i;
    }

    i = 0;
    while (sent_cstring2[i] != '\0'){
        cstring[i + length1] = sent_cstring2[i];
        ++i;
    }

    string_length = length1 + length2;
    cstring[string_length] = '\0';
}

// Takes a cstring and a length for that cstring and returns a MyString object
MyString::MyString(char* sent_cstring, int desired_length){
    int actual_length = 0;

    while (sent_cstring[actual_length] != '\0'){
        ++actual_length;
    }

    if (desired_length > actual_length){
        desired_length = actual_length;
    }

    cstring = new char[desired_length + 1]; // For null terminator

    for (int i = 0; i < desired_length; ++i){
        cstring[i] = sent_cstring[i];
    }

    cstring[desired_length] = '\0';
    string_length = desired_length;
}

// Default value, just a null terminator
MyString::MyString(){
    cstring = new char[1];
    cstring[0] = '\0';

    string_length = 0;
}

MyString::~MyString(){
    if (debug) std::cout << "MyString Object: " << cstring << " deleted" << std::endl;
    delete[] cstring;
    cstring = nullptr; // Safety
}

int MyString::length(){
    return string_length;
}

// Returns the location of the null terminator
char* MyString::last(){
    return &cstring[string_length];
}

char* MyString::first(){
    return cstring;
}

// Returns the location to the first element/cstring
char* MyString::get_cstring(){
    return cstring;
}

// Returns a new String from and existing one, zero indexed (0, 2) {'a', 'b'}
MyString MyString::sub_string(int start, int end){
    return MyString(&cstring[start], end);
}

// Deference operator
char MyString::operator[](int i){
    if (i > string_length || i < 0){
        std::cerr << "Out of range" << std::endl; //catch(out_of_range &e){e.what(); }
        throw std::out_of_range("My out of range");
    }
    return cstring[i];
}

// If they're at the same address they must be the same, as they're immutable objects
// If they consist of the same character array, they must also be the same
bool MyString::operator==(MyString& lhs_string){
    // Same address check
    if (this == &lhs_string){
        return true;
    }

    if (string_length != lhs_string.length()){
        return false;
    }


    for (int i = 0; i < string_length + 1; ++i){
        if (cstring[i] != lhs_string[i]){
            std::cout << cstring[i] << " Doesn't equal " << lhs_string[i] << std::endl;
            return false;
        }
    }

    return true; // All conditions are met, the string is the same
}

// Adds one MyString to another
MyString MyString::operator+(MyString& lhs_string){
    return MyString(get_cstring(), lhs_string.get_cstring());
}

// Typical += operator, RHS gets LHS added to it
MyString& MyString::operator+=(MyString& lhs_string){
    char* temp_string = new char[string_length + lhs_string.length() + 1];

    for (int i = 0; i < length(); ++i){
        temp_string[i] = cstring[i];
    }

    for (int i = 0; i < lhs_string.length(); ++i){
        temp_string[i + length()] = lhs_string[i];
    }

    temp_string[string_length + lhs_string.length()] = '\0';

    delete[] cstring;

    cstring = temp_string;
    string_length = string_length + lhs_string.length();

    return *this;
}

// Deletes old LHS and makes a deep copy of RHS
MyString& MyString::operator=(MyString& lhs_string){
    delete[] cstring;
    cstring = new char[lhs_string.length() + 1];

    // Should copy over the terminator
    for (int i = 0; i <= lhs_string.length(); ++i){
        cstring[i] = lhs_string[i];
    }

    string_length = lhs_string.length();

    return *this;
}