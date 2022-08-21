#include <iostream>
#include <vector>

template<typename T>
class square_matrix{
    std::vector<std::vector<T>> items{};

    public:
        square_matrix(){};
        square_matrix(const unsigned int& dim);
        square_matrix(const square_matrix& matrix);

        unsigned int size() const;
        void print() const;
        int& at(const unsigned int& row,const unsigned int& col);
        const int& at(const unsigned int& row, const unsigned int& col) const;

        bool is_all_primes() const;

        square_matrix reduce(const unsigned int& row,const unsigned int& col) const;

        ~square_matrix();
};


