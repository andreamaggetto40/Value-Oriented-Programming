#include <iostream>
#include <vector>

using std::cout; using std::vector;

/**
 * Despite the valuable features C++ own, a missing important one is represented by the garbage collection.
 * It happens when an heap memory value is no longer pointed by something on the stack; In this way a memory leak occurs
 * In order to prevent it, a safe way to be sure about deleating all the heap memory values is to implement a shared pointer
 */
template<typename T>
class shared_ptr{
    unsigned int counter{0};
    T item{};
    using T_ptr = T*;
    T_ptr to_put_heap{};

    public:
        inline shared_ptr(){};
        inline shared_ptr(const T& item) : counter(1){
            to_put_heap = new T{};
            *to_put_heap = item;
        }
        inline shared_ptr(const T_ptr& pointer_to_item) : counter(++counter){
            pointer_to_item = to_put_heap;
        }
        inline ~shared_ptr(){
            if(!counter) delete to_put_heap;
        }
};

int main(int argc, char const *argv[])
{
    
}
