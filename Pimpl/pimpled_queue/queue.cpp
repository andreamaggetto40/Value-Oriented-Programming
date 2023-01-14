#include <iostream>
#include "queue.hpp"
#include <vector>

using std::vector; using std::cout;

template<typename T>
struct queue<T>::impl{
    vector<T> items{};
};

template<typename T>
queue<T>::queue(){
    pimpl = new impl;
}

template<typename T>
queue<T>::queue(const size_t& size, const T& init){
    pimpl = new impl;   
    pimpl->items = vector<T>(size,init);
}

template<typename T>
size_t const queue<T>::size() const{
    return pimpl->items.size();
}

template<typename T>
void queue<T>::print_queue() const{
    for(const T it : pimpl->items) cout << it <<"\n";
}



int main(int argc, char const *argv[])
{
    queue<int> first{10,5};

    first.print_queue();

    
}
