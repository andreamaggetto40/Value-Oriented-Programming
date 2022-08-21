template <typename T>
class double_list{
    struct node{
        struct node* prev;
        T info;
        struct node* next;
    };

    struct node* head; struct node* tail;

    bool make_palindrome(node* first,node* second){
        if(first and second){
            if(first == second) return true;
            else{
                return first->info == second->info and make_palindrome(first->next,second->prev);
            }
        }
    }

    public:
        double_list();

        void append(const T item);
        void print(); 
        void print_reverse();
        bool is_palindrome();

};

template<typename T>
double_list<T>::double_list(){
    head = tail = nullptr;
}

template<typename T>
void double_list<T>::append(const T item){
    struct node* to_append = new node(); to_append->prev = nullptr; to_append->info = item; to_append->next = nullptr;

    if(!head and !tail){
        head = tail = to_append;
    }
    else{
        tail->next = to_append; to_append->prev = tail; tail = tail->next;
    }
}

template<typename T>
void double_list<T>::print(){
    for(; head; std::cout<<head->info<<std::endl,head = head->next);
}

template<typename T>
void double_list<T>::print_reverse(){
    for(; tail; std::cout<<tail->info<<std::endl,tail = tail->prev);
}

template<typename T>
bool double_list<T>::is_palindrome(){
    return make_palindrome(head,tail);
}

