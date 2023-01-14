#include <iostream>
#include <cassert>
#include "list.hpp"

template<typename T>
struct linked_list<T>::impl{
    cell<T>* head{};
    cell<T>* tail{};

    unsigned int size{0};

    void destroy(cell<T>* cl){
        if(cl) destroy(cl->next);
        delete cl;
    }

    void remove(cell<T>* start){
        cell<T>* outer{start};
        cell<T>* inner{start};

        while(outer){
            while(inner->next){
                if(inner->next->info == outer->info){
                    cell<T>* to_delete = new cell<T>{};
                    to_delete = inner->next;
                    inner->next = to_delete->next;
                    delete to_delete;
                }
                else inner = inner->next;
            }
            outer = inner = outer->next;
        }
    }
};

template<typename T>
linked_list<T>::linked_list(){
    pimpl = new impl{};
}

template<typename T>
linked_list<T>::linked_list(const unsigned int& size, const T& init){
    pimpl = new impl{};
    cell<T>* iterator{};

    for(size_t i{0}; i < size; ++i){
        cell<T>* to_add = new cell<T>{};
        to_add->info = init;
        to_add->next = nullptr;

        if(!i){
            pimpl->head = pimpl->tail = iterator = to_add;
        }
        else{
            iterator->next = pimpl->tail = to_add;
            iterator = iterator->next;
        }
        ++pimpl->size;
    }
}

template<typename T>
linked_list<T>::linked_list(const linked_list<T>& to_copy){
    pimpl = new impl{};
    
    for(cell<T>* iterator = to_copy.pimpl->head; iterator; iterator = iterator->next){
        push_back(iterator->info);
    }
}

template<typename T>
linked_list<T>::~linked_list(){
    pimpl->destroy(pimpl->head);
    delete pimpl;
    std::cout << "Destructor called!";  
}

template<typename T>
void linked_list<T>::print() const{
    for(cell<T>* iterator = pimpl->head; iterator != nullptr; iterator = iterator->next) std::cout << iterator->info << "\n";
}

template<typename T>
void linked_list<T>::push_back(const T& value){ 
    cell<T>* to_add = new cell<T>{};

    to_add->info = value;
    to_add->next = nullptr;

    if(!pimpl->head){
        pimpl->head = pimpl->tail = to_add;
    }
    else{  
        pimpl->tail->next = to_add;
        pimpl->tail = pimpl->tail->next;
    }

    ++pimpl->size;
}

template<typename T>
void linked_list<T>::push_front(const T& value){
    cell<T>* to_add = new cell<T>{};

    to_add->info = value;

    if(!pimpl->head){
        to_add->next = nullptr;
        pimpl->head = pimpl->tail = to_add;
    }
    else{
        to_add->next = pimpl->head;
        pimpl->head = to_add;
    }

    ++pimpl->size;
}

template<typename T>
unsigned int linked_list<T>::size() const{
    return pimpl->size;
}

template<typename T>
T& linked_list<T>::operator[](const unsigned int& pos){
    assert(pos >= 0 and pos < size());

    cell<T>* iterator{pimpl->head};

    for(size_t i{0}; i < pos; ++i, iterator = iterator->next);

    return iterator->info;
}

template<typename T>
const T& linked_list<T>::operator[](const unsigned int& pos) const{
    return operator[](pos);
}

template<typename T>
void linked_list<T>::remove_duplicates(){
    pimpl->remove(pimpl->head);
}

template<typename T>
linked_list<T>& linked_list<T>::sorted_merge(const linked_list<T>& l1, const linked_list<T>& l2){
    cell<T>* l1_it{l1.pimpl->head};
    cell<T>* l2_it{l2.pimpl->head};

    while(l1_it and l2_it){
        if(l2_it->info < l1_it->info){
            push_back(l2_it->info);
            l2_it = l2_it->next;
        }
        else{
            push_back(l1_it->info);
            l1_it = l1_it->next;
        }
    }
    cell<T>* what_left{l1_it ? l1_it : l2_it};
    
    while(what_left){
        push_back(what_left->info);
        what_left = what_left->next;
    }

    return *(this);
}

template<typename T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& to_copy){       
    if(this != &to_copy){
        if(pimpl->head){
            pimpl->destroy(pimpl->head);
        }
    }
    
    for(size_t i{0}; i < to_copy.size(); ++i){
        push_back(to_copy[i]);
    }

    return *(this);
}

int main(int argc, char const *argv[])
{
    linked_list<int> first{5,10},second{6,20};

    first = second;

    first.print();


}



