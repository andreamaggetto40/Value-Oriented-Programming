template<typename T>
struct cell{
    T info{};
    cell<T>* next{};
};

template<typename T>
class linked_list{
    struct impl;
    impl* pimpl;

    public:
        linked_list();
        linked_list(const unsigned int& size, const T& init);
        linked_list(const linked_list<T>& to_copy);
        ~linked_list();
        linked_list<T>& operator=(const linked_list<T>& to_copy);
        void print() const;
        void push_back(const T& value);
        void push_front(const T& value);
        unsigned int size() const;
        T& operator[](const unsigned int& pos);
        const T& operator[](const unsigned int& pos) const;
        void remove_duplicates();
        linked_list<T>& sorted_merge(const linked_list<T>& l1, const linked_list<T>& l2);
};



