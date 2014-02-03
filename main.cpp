#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include "my_string_library.h"

void scope(){
    // Fixes: conversion from string literal to 'char *' is deprecated [-Wdeprecated-writable-strings]
    char num_string[] = "0123456789";
    char* ptr_num_string = num_string;

    MyString more_nums(ptr_num_string);
    for (char* i = (char*)more_nums.first(); i != (char*)more_nums.last(); ++i){
        std::cout << (void*)i << ':' << *i << std::endl;
    }

    MyString* nums = new MyString(ptr_num_string);
    for (char* i = (char*)nums->first(); i != (char*)nums->last(); ++i){
        std::cout << (void*)i << ':' << *i << std::endl;
    }

    delete nums;
}


void scope2(){
    // Fixes: conversion from string literal to 'char *' is deprecated [-Wdeprecated-writable-strings]
    char a_cstring[][5] = {"blah", " bob"};
    char* ptr_a_cstring[] = {a_cstring[0], a_cstring[1]};

    MyString more_nums[2] = { MyString(ptr_a_cstring[0]), MyString(ptr_a_cstring[1]) };

    std::cout << more_nums[0] << more_nums[1] << std::endl;
}

int main(){
    scope();
    scope2();
}