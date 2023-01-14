#include <iostream>


template<typename T>
struct node{
        T info{};
        struct node* prev{};
        struct node* next{};
    };

template<typename T>
class doubly_linked_list{   

    struct impl;
    impl* pimpl;

    public:
        using value_type = T;

        doubly_linked_list();
        doubly_linked_list(const size_t& size, const T& init);
        ~doubly_linked_list();
        doubly_linked_list<T>& operator=(const doubly_linked_list<T>& to_copy);
        void add(const std::string& s);
        void print() const;
};
       
        