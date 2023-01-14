#include <memory>

template<typename T>
struct node{
    T info{};
    node* next;
};

template<typename T>
class circular_list{    
    struct impl;
    impl* pimpl;

    public:
        circular_list();
        circular_list(const size_t& size, const T& init);
        size_t size() const;
        void linearize();
        void print() const;
        bool is_empty();
};