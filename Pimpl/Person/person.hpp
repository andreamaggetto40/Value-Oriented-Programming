#include <iostream>

/*
    Exploiting the C++ Pimpl pattern, our main object has to be shifted into two main parts:
    Interface: The .hpp file, containing, on the public part, all the methods whereas the implementation and the pointer to implementation on the private one
    Actual implementation: In the .Cpp file, where, through impl and pimpl the object can be build properly.
*/

class person{
    struct impl;
    impl* pimpl;

    public:
        person();
        person(const std::string& name, unsigned int& age);
        person(const person& to_copy);
        void to_string() const;
};