#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include "my_string_library.h"

void scope(){

    MyString more_nums("0123456789");
    for (char* i = (char*)more_nums.first(); i != (char*)more_nums.last(); ++i){
        std::cout << (void*)i << ':' << *i << std::endl;
    }

    MyString* nums = new MyString("123456789");
    for (char* i = (char*)nums->first(); i != (char*)nums->last(); ++i){
        std::cout << (void*)i << ':' << *i << std::endl;
    }

    delete nums;
}

void scope2(){
    MyString more_nums[2] = { MyString("blah"), MyString(" other blah") };

    std::cout << more_nums[0] << more_nums[1] << std::endl;
}

int main(){
    scope();
    scope2();
}