#include <iostream>

using std::string; using std::cout;

//the local file wants to stress the mechanism wrapped around the Inheritance and the Java-like interfaces in C++ language

class person{
    string name; uint8_t age;

    public:
        inline person();
        explicit inline person(string name, uint8_t age) : name(name), age(age){};
        virtual void greet() = 0; //pure virtual function; To be overrided
};

class athlete{
    string sport;

    public:
        inline athlete();
        explicit inline athlete(string& sport) : sport(sport){};
        inline string get_sport() const{
            return sport;
        }
};

class student : public person, public athlete{ //An important C++ Inheritance related feature: The language supports multiple inheritance whereas Java does not
    string uni_name;

    public:
        inline student() : person() {};
        explicit inline student(string name, uint8_t age, string uni_name,string sport) : person(name,age), athlete(sport), uni_name(uni_name){};
        inline void greet(){
            cout<<"Hi there, I'm a student!"<<"\n";
        }
};

int main(int argc, char const *argv[])
{   
    
}
