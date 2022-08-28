#include <iostream>
#include <vector>
#include <time.h>
#include <cassert>

/**
 * matrix 
 * This library wants to be a compound of the most useful functions to create and manage a matrix
 */

using std::cout; using std::vector; 

class matrix{
    using vect = vector<vector<int>>;
    vect items;
    int rows{},cols{};

    public:
        inline matrix() = default;
        inline matrix(const int rows, const int cols) : rows(rows), cols(cols){
            assert(rows > 0 and cols > 0);
            items.resize(rows);
            for(size_t i{0}; i < rows; ++i){
                items.at(i).resize(cols);
            }
        }
        inline matrix(const matrix& to_copy) : rows(to_copy.rows), cols(to_copy.cols){
            items.resize(to_copy.rows);
            for(size_t i{0}; i < rows; ++i){
                items.at(i).resize(cols);
                for(size_t j{0}; j < cols; ++j){
                    items.at(i).at(j) = to_copy.items.at(i).at(j);
                }
            }
        }
        inline matrix trasposed() const{
            matrix output{cols, rows};

            for(size_t i{0}; i < rows; ++i){
                for(size_t j{0}; j < cols; ++j){
                    output.items.at(j).at(i) = items.at(i).at(j);
                }
            }

            return output;
        }
        inline void fill_matrix(){
            srand(time(NULL));
            for(size_t i{0}; i < rows; ++i){
                for(size_t j{0}; j < cols; ++j){
                    items.at(i).at(j) = rand() % 100;
                }
            }
        }
        inline matrix identity(int size) const{
            matrix output{size,size};

            for(size_t i{0}; i < size; ++i){
                output.items.at(i).at(i) = 1;
            }

            return output;
        }
        inline matrix sum(const matrix& to_sum) const{
            assert(rows == to_sum.rows and cols == to_sum.cols);
            matrix output{rows,rows};

            for(size_t i{0}; i < rows; ++i){
                for(size_t j{0}; j < rows; ++j){
                    output.items.at(i).at(j) = items.at(i).at(j) + to_sum.items.at(i).at(j);
                }
            }

            return output;
        }
        inline void print() const{
            for(size_t i{0}; i < rows; ++i){
                for(size_t j{0}; j < cols; ++j){
                    cout<<items.at(i).at(j) <<" ";
                }
                cout<<"\n";
            }
        }
};

int main(int argc, char const *argv[])
{                                               
    
}
