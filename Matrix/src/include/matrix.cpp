#include <iostream>
#include <vector>
#include <time.h>
#include <cassert>
/**
 * matrix 
 * @brief: This library wants to be a compound of the most useful functions to create and manage a matrix
 */

using std::cout; using std::vector; 

class matrix{
    using vect = vector<vector<int>>;
    vect items;
    int rows{},cols{};

    public:
        /** Default constructor
         * @brief Construct a new matrix object
         * 
         */
        inline matrix() = default;
        /** Parametered constructor
         * @brief Construct a new matrix object
         * @param rows : matrix rows
         * @param cols : matrix cols
         */
        inline matrix(const int rows, const int cols) : rows(rows), cols(cols){
            assert(rows > 0 and cols > 0);
            items.resize(rows);
            for(size_t i{0}; i < rows; ++i){
                items.at(i).resize(cols);
            }
        }
        /** Copy constructor
         * @brief Construct a new matrix object
         * @param to_copy : Matrix to be copied
         */
        inline matrix(const matrix& to_copy) : rows(to_copy.rows), cols(to_copy.cols){
            items.resize(to_copy.rows);
            for(size_t i{0}; i < rows; ++i){
                items.at(i).resize(cols);
                for(size_t j{0}; j < cols; ++j){
                    items.at(i).at(j) = to_copy.items.at(i).at(j);
                }
            }
        }
        /** Transposition of a matrix
         * @brief Method that builds the transposed matrix, give another one
         * @return matrix : Transposed matrix
         */
        inline matrix trasposed() const{
            matrix output{cols, rows};

            for(size_t i{0}; i < rows; ++i){
                for(size_t j{0}; j < cols; ++j){
                    output.items.at(j).at(i) = items.at(i).at(j);
                }
            }

            return output;
        }
        /** 
         * @brief Method that fills a matrix with random integer values
         * 
         */
        inline void fill_matrix(){
            srand(time(NULL));
            for(size_t i{0}; i < rows; ++i){
                for(size_t j{0}; j < cols; ++j){
                    items.at(i).at(j) = rand() % 100;
                }
            }
        }
        /**
         * @brief Identity matrix creator method
         * 
         * @param size : Size of the matrix (iif size mod 2 = 0 -> it's possibile to create the identity matrix)
         * @return matrix : Identity matrix
         */
        inline matrix identity(int size) const{
            matrix output{size,size};

            for(size_t i{0}; i < size; ++i){
                output.items.at(i).at(i) = 1;
            }

            return output;
        }
        /** 
         * @brief Method to sum two matrix, and outcome the resulted one
         * 
         * @param to_sum : the matrix to add
         * @return matrix : sum matrix
         */
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
        /**
         * @brief Method that calculates the product matrix
         * 
         * @param to_mul : Matrix to multiply
         * @return matrix : Product matrix
         */
        inline matrix product(const matrix& to_mul) const{
            assert(cols == to_mul.rows);
            matrix output{rows, to_mul.cols}; int amount{0};

            
        }
        /**
         * @brief Method that outputs a matrix trace
         * 
         * @return int: The calculated trace
         */
        inline int trace() const{
            int output{items.at(0).at(0) + items.at(rows - 1).at(rows - 1)};

            for(int counter{1}, i{1}, j {1}; counter < rows - 1; ++counter, ++i, ++j){
                output += items.at(i).at(j);
            }

            return output;
        }
        /**
         * @brief Simple method that prints a matrix
         * 
         */
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
    matrix first{3,5}; first.fill_matrix(); first.print();

    cout<<first.trace() <<"\n";
}
