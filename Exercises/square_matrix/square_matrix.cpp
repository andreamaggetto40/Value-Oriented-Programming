#include "square_matrix.hpp"
//given an unsigned 'dim', build a matrix square that can perform some operations

using std::cout; using std::endl;

template<typename T>
square_matrix<T>::square_matrix(const unsigned int& dim){
    items.resize(dim);

    /*
    first way for the constructor
    for(size_t i{0}; i < dim; ++i){
        for(size_t j{0}; j < dim; ++j){
            items.at(j).push_back(0);
        }
    }*/


    //second way: It builds an empty cells composed square matrix
    for(size_t i{0}; i < dim; ++i){
        items.at(i).resize(dim);
    }

    for(size_t i{0}; i < dim; ++i){
        for(size_t j{0}; j < dim; ++j){
            at(i,j) = ((i * dim) + (j + 1));
        }
    }
}

//returns the square matrix size
template<typename T>
unsigned int square_matrix<T>::size() const{
    return items.size();
}

//returns the matrix item located at the specific (row;col) position. Used as left-value
template<typename T>
int& square_matrix<T>::at(const unsigned int& row,const unsigned int& col){    
    return items.at(row).at(col);
}

//overloaded method; returns the matrix item located at the specific (row;col) position. Used as right-value
template<typename T>
const int& square_matrix<T>::at(const unsigned int& row, const unsigned int& col) const{
    return this->at(row,col);
}

//copy-constructor 
template<typename T>
square_matrix<T>::square_matrix(const square_matrix& matrix){  
    unsigned matrix_size{matrix.size()};

    items.resize(matrix_size);

    for(size_t i{0}; i < matrix_size; ++i){
        for(size_t j{0}; j < matrix_size; ++j){
            items.at(i).at(j) = matrix.at(i,j);
        }
    }
}

//class method that establish whether all the items are prime or not
template<typename T>
bool square_matrix<T>::is_all_primes() const{
    bool check{false};

    for(size_t i{0}; i < size() and !check; ++i){
        for(size_t j{0}; j < size(); ++j){
            for(int x{2}; x < at(i,j); ++x){
                check |= (!(at(i,j) % x));
            }
        }
    }

    return check;
}

//reduce the current matrix through Gauss elimination algorithm 
template<typename T>
square_matrix<T> square_matrix<T>::reduce(const unsigned int& row,const unsigned int& col) const{   
    unsigned int current_x{0},current_y{0},sz{size()};
    square_matrix output{sz - 1};

    for(size_t i{0}; i < sz; ++i){
        for(size_t j{0}; j < sz; ++j){
            if(i + 1 != row){
                if(j + 1 != col){
                    output.at(current_x,current_y) = at(i,j);
                    ++current_y;
                }
            }
        }
        ++current_x;
    }

    return output;
}

//method to print the matrix
template<typename T>
void square_matrix<T>::print() const{
    size_t sz{size()};

    for(size_t i{0}; i < sz; ++i){
        for(size_t j{0}; j < sz; ++j){
            cout<<items.at(i).at(j) << " ";
        }
        cout<<endl;
    }
}

//destructor method; considering no value is built upon hear memory, the destructor is always called
template<typename T>
square_matrix<T>::~square_matrix() {};

int main(int argc, char const *argv[])
{   
    
}
