#include <vector>
#include <iostream>
using std::cout; using std::endl; using std::string; using std::vector; 

template<typename T>
class list{
    struct node{
        T info;
        struct node* next;
    };

    struct node* head;
    struct node* tail;

    void create_recursion(struct node* cell){
        if(cell){
            create_recursion(cell->next);

            if(!cell->next){
                cout<<"Last item!";
            }
            cout<<cell->info<<endl;
        }
    };

    void add_wowels(struct node* cell,vector<char>& vect){
        if(cell){
            if(cell->info == 'a' or cell->info == 'e' or cell->info == 'i' or cell->info == 'o' or cell->info == 'u'){
                vect.push_back(cell->info);
            }
            add_wowels(cell->next,vect);
        }
    }

    void delete_even(node* cell){
        if(cell){
            if(!(cell->info % 2)){
                node* destroyer{cell};

                if(!cell->next) delete destroyer;
                else{
                    cell = cell->next;
                    delete destroyer;
                    delete_even(cell);
                }
            }
            else delete_even(cell->next);
        }
    }

    void make_copy(node* cell,list<T>& output){
        if(cell){
            make_copy(cell->next,output);
            output.append(cell->info);
        }
    }

    void make_cumulative_sum(node* cell,list<T>& output){
        if(cell){
            make_cumulative_sum(cell->next,output);
            int info{0};

            if(!cell->next){
                output.append(cell->info);
                info = cell->info;
            }
            else{
                output.append(cell->info + info);
                info = cell->info;
            }
        }
    }

    void make_delete_consec(node* cell){
        if(cell){
            if(cell->info == cell->next->info){
                node* destroyer{cell};

                cell = cell->next;
                delete destroyer;

                make_delete_consec(cell);
            }
            else make_delete_consec(cell->next);
        }
    }

    int make_delete_odds(node* cell, unsigned int amount){
        if(!cell) return 0;
        else{
            if(!amount) return 0;
            else{
                if(cell->info % 2){
                    node* destroyer{cell};
                    cell = cell->next;
                    delete destroyer;
                    return 1 + make_delete_odds(cell,amount - 1);
                }
                else return 0 + make_delete_odds(cell->next,amount);
            }
        }
    }


    public:
        list();


        void append(const T& item);
        size_t size();
        void print();
        unsigned period();
        void make_circular();
        list merge_list(const list<T>& l1, const list<T>& l2) const;
        void print_reverse();
        string concat(int pos,int len);
        void deleater() const;
        void wowels_appender(vector<char>& vect);
        void delete_even_numbers();
        void delete_consec();
        unsigned int delete_amount_odds(unsigned int odds_to_delete);

        struct node* operator=(list<T> to_copy);

        struct node* even_odd_list() const;

        list copy_reverse();
        list cumulative_sum();
};

template<typename T>
list<T>::list(){    
    head = tail = nullptr;
}

template<typename T>
list<T> list<T>::merge_list(const list<T>& l1, const list<T>& l2) const{
    list<T> output{};

    while(l1.head and l2.head){
        if(l1.head->info < l2.head->info){
            output.append(l1.head->info); l1.head = l1.head->next;
        }
        else{
            output.append(l2.head->info); l2.head = l2.head->next;
        }
    }

    if(l1.head){
        while(l1.head){
            output.append(l1.head->info); l1.head = l1.head->next;
        }
    }
    else{
        while(l2.head){
            output.append(l2.head->info); l2.head = l2.head->next;
        }
    }

    return output;
}

template<typename T>
void list<T>::append(const T& item){
    struct node* to_append = new node(); to_append->info = item; to_append->next = nullptr;

    if(!head){
        head = tail = to_append;
    }
    else{
        tail->next = to_append;
        tail = tail->next;
    }
}

template<typename T>
size_t list<T>::size(){
    size_t counter{0};

    for(; head; ++counter, head = head->next);

    return counter;
}

template<typename T>
void list<T>::print(){
    for(; head; cout<<head->info<<endl,head = head->next);
}

/*template<typename T>
struct node* list<T>::operator=(list<T> to_copy){
    
}*/

template<typename T>
unsigned list<T>::period(){
    unsigned frequency{0};

    if(head){
        frequency = 1; struct node* check{head}; struct node* iterator{head->next};

        for(; iterator and iterator->info != check->info; ++frequency,iterator = iterator->next);
    }

    return frequency;
}

template<typename T>
void list<T>::make_circular(){
    tail->next = head;
}



template<typename T>
void list<T>::print_reverse(){    
    create_recursion(head);
}

template<typename T>
string list<T>::concat(int pos, int len){
    string output{}; struct node* iterator{head};

    for(size_t i{0}; i < pos and iterator; ++i, iterator = iterator->next);
    for(size_t i{0}; i < len and iterator; ++i, output += iterator->info, iterator = iterator->next);

    return output;

}

template<typename T>
void list<T>::deleater() const{ 
    node* iterator{head},destroyer{},matcher{head};

    while(iterator){
        destroyer = iterator;

        if(head == matcher) head = matcher = matcher->next;
        else matcher->next = iterator->next;
        iterator = iterator->next->next;
        
        if(!iterator->next) matcher->next->next = nullptr;

        delete destroyer;
    }
}

template<typename T>
void list<T>::wowels_appender(vector<char>& vect){        
    add_wowels(head,vect);
}

template<typename T>
void list<T>::delete_even_numbers(){
    delete_even(head);
}

template<typename T>
list<T> list<T>::copy_reverse(){
    list output;
    make_copy(head,output);

    return output;
}

template<typename T>
list<T> list<T>::cumulative_sum(){  
    list output{};

    make_cumulative_sum(head,output);

    return output;
}

template<typename T>
void list<T>::delete_consec(){
    make_delete_consec(head);
}

template<typename T>
unsigned list<T>::delete_amount_odds(unsigned int odds_to_delete){
    return make_delete_odds(head,odds_to_delete);
}
