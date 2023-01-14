#include "dl.hpp"

using std::cout; using std::string;

template<typename T>
struct doubly_linked_list<T>::impl{ 
    node<T>* head{};
    node<T>* tail{};

    size_t size{0};

    void destroy(node<T>* n){
        if(n) destroy(n->next);
        delete n;
    }
};

template<typename T>
doubly_linked_list<T>::doubly_linked_list(){
    pimpl = new impl{}; 
}

template<typename T>
doubly_linked_list<T>::doubly_linked_list(const size_t& size, const T& init){   
    pimpl = new impl{};
    node<T>* iterator{};

    for(size_t i{0}; i < size; ++i){
        node<T>* to_add = new node<T>{};

        to_add->next = nullptr;
        to_add->info = init;

        if(!i){
            to_add->prev = nullptr;
            pimpl->head = pimpl->tail = iterator = to_add;
        }
        else{
            to_add->prev = iterator;
            iterator->next = to_add;
            iterator = pimpl->tail = iterator->next;
        }

        ++pimpl->size;
    }
}

template<typename T>
void doubly_linked_list<T>::print() const{
    for(node<T>* iterator = pimpl->head; iterator; iterator = iterator->next) cout << iterator->info << "\n";
}

template<typename T>
void doubly_linked_list<T>::add(const string& s){   
    //Only for the operands that support the </>/= operators
    node<T>* to_add = new node<T>{};
    to_add->info = s;

    if(!pimpl->head){
        to_add->prev = to_add->next = nullptr;
        pimpl->head = pimpl->tail = to_add;
    }
    else{
        node<T>* iterator{pimpl->head};

        while(iterator->info < s) iterator = iterator->next;

        if(!iterator->prev){
            to_add->next = iterator;
            to_add->prev = nullptr;
            iterator->prev = to_add;
            iterator = pimpl->head = to_add;
        }
        else {
            to_add->next = iterator;
            iterator->prev->next = to_add;
            to_add->prev = iterator->prev;
            iterator->prev = to_add;
        }
    }
}

template<typename T>
doubly_linked_list<T>::~doubly_linked_list(){
    pimpl->destroy(pimpl->head);
    delete pimpl;
}

int main(int argc, char const *argv[])
{
    doubly_linked_list<string> first{5,"Hello world"};

    first.add("andrea");

    first.print();

    
}
