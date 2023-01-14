#include <iostream>
#include "circular_list.hpp"


template<typename T>
struct circular_list<T>::impl{
    node<T>* head{};
    node<T>* tail{};

    size_t size{0};
};

template<typename T>
circular_list<T>::circular_list(){
    pimpl = new impl{};
}

template<typename T>
circular_list<T>::circular_list(const size_t& size, const T& init){ 
    pimpl = new impl{};
    node<T>* iterator{};

    for(size_t i{0}; i < size; ++i){
        node<T>* to_add = new node<T>{};
        
        to_add->info = init;

        if(!i){
            to_add->next = to_add;
            pimpl->head = pimpl->tail = iterator = to_add;
        }
        else{
            to_add->next = pimpl->head;
            iterator->next = pimpl->tail = to_add;
            iterator = iterator->next;
        }

        ++pimpl->size;
    }
}

template<typename T>
void circular_list<T>::print() const{   
    node<T>* iterator{pimpl->head};

    do{
        std::cout << iterator->info << "\n";
        iterator = iterator->next;
    } while(iterator != pimpl->head);
}

template<typename T>
bool circular_list<T>::is_empty(){
    return !size;
}

template<typename T>
void circular_list<T>::linearize(){
    pimpl->tail->next = nullptr;


}


int main(int argc, char const *argv[])
{   
    circular_list<int> cl{5,10};

    cl.print();
}
