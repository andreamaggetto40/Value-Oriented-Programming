#include <iostream>

template<typename T>
class matrix{
    struct impl;
    impl* pimpl;

    public:
        matrix();
        matrix(const size_t& rows, const size_t& cols);
        ~matrix();
        matrix(const matrix<T>& to_copy);
        T& at(const size_t& row, const size_t& col);
        const T& at(const size_t& row, const size_t& col) const;
        matrix<T> reduce(const size_t& row, const size_t& col);
        void print() const;
        size_t size() const; 
};