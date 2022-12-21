#include "person.hpp"

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




