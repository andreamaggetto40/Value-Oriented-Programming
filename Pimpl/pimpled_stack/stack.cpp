#include <iostream>
#include "stack.hpp"
#include <vector>

using std::vector;

template<typename T>
struct stack<T>::impl{
    vector<T> items{};
};

template<typename T>
stack<T>::stack(){
    pimpl = new impl;
}

template<typename T>
stack<T>::stack(const size_t& size, const T& init){
    pimpl = new impl;
    pimpl->items.resize(size);

    for(size_t i{0}; i < size; ++i){
        pimpl->items.at(i) = init;
    }
}

template<typename T>
size_t const stack<T>::size() const{
    return pimpl->items.size();
}

template<typename T>
void stack<T>::print_stack() const{
    for(int i = pimpl->items.size() - 1; i >= 0; --i){
        std::cout << pimpl->items.at(i) <<"\n";
    }
}


int main(int argc, char const *argv[])
{
    stack<int> first{5,4};

    first.print_stack();

    
}
