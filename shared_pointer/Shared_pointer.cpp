#include <iostream>
#include <vector>

using std::cout; using std::vector;

/**
 * Despite the valuable features C++ own, a missing important one is represented by the garbage collection.
 * It happens when an heap memory value is no longer pointed by something on the stack; In this way a memory leak occurs
 * In order to prevent it, a safe way to be sure about deleating all the heap memory values is to implement a shared pointer
 */
template <typename T>
class shared_ptr{
    T item;
    vector<T*> pointers{};

    public:
        inline shared_ptr(){};
        inline shared_ptr(T item) : item(item){};
        inline shared_ptr(T*& item){
            pointers.push_back(item);
        }
        inline ~shared_ptr(){
            if(!pointers.size()) delete *item;
        }
};


int main(int argc, char const *argv[])
{   
    
}
