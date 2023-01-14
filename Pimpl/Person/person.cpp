#include "person.hpp"

/*
    The .cpp file contains the actual object implementation.
    It's divided into two main parts:
        impl: Struct (therefore, the access method is public by default), which contains all the object and functions, If needed
        method references: The actual methods implementation of the object
*/

struct person::impl{
    std::string name{}; unsigned int age{0};
};

person::person(){
    pimpl = new impl{};
};

person::person(const std::string& name, unsigned int& age){
    pimpl = new impl{};
    pimpl->age = age;
    pimpl->name = name;
};

void person::to_string() const{
    std::cout <<"Name is : " <<pimpl->name <<" " <<"Age is : " <<pimpl->age <<"\n";
};




