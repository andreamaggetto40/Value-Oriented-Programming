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
    vector<vector<int>> items{};
    int rows{},cols{};

    bool is_no_zero(const vector<int>& vect){
        bool check{true};
    
        for(size_t i{0}; i < vect.size() and check; ++i){
            check &= vect.at(i);
        }

        return check;
    }

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
        /**
         * @brief Method to calculate main diagonal of a matrix. 
         * A matrix main diagonal is defined as the values set : (x,y) -> x == y
         * @return Matrix diagonal
         */
        inline vector<int> get_main_diagonal() const{
            vector<int> diagonal{}; diagonal.resize(rows);

            for(size_t i{0}; i < rows; ++i){
                diagonal.at(i) = items.at(i).at(i);
            }

            return diagonal;
        }
        /**
         * @brief Method to check whether a matrix is diagonal
         * A matrix is diagonal iif for any n,m : n = (x,y), x == y and m = (a,b), a # b -> n # 0 and m = 0
         * @return bool : check whether matrix is diagonal or not.
         */
        inline bool is_diagonal() {
            bool check{true}; 

            if(is_no_zero(get_main_diagonal())){
                for(size_t i{0}; i < rows and check; ++i){
                    for(size_t j{0}; j < cols; ++j){
                        if(i != j){
                            check &= !(items.at(i).at(j));
                        }
                    }
                }
            }
            else check = false;

            return check;
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
         * @brief Get the Matrix rows
         * 
         * @return size_t : rows number
         */
        inline size_t get_rows() const{
            return rows;
        }
        /**
         * @brief Get the Matrix cols
         * 
         * @return size_t : cols number
         */
        inline size_t get_cols() const{
            return cols;
        }
        /**
         * @brief Method that calculates the product matrix
         * 
         * @param to_mul : Matrix to multiply
         * @return matrix : Product matrix
         */
        inline matrix product(const matrix& to_mul) const{
            assert(cols == to_mul.rows);
            matrix product_matrix{rows,to_mul.cols};

            int mul{0};

            for(size_t i{0}; i < rows; ++i){
                for(unsigned int counter{0}; counter < rows; ++counter){
                    for(size_t j{0}; j < cols; ++j){
                        mul += items.at(i).at(j) * to_mul.items.at(j).at(counter);
                    }
                    product_matrix.items.at(i).at(counter) = mul;
                    mul = 0;
                }
                mul = 0; 
            }

            return product_matrix;
        }
        /**
         * @brief Method that calculates the matrix determinant
         * 
         * @return int : Determinant
         */
        inline int determinant() const{
            assert(rows == cols);

        }
        /**
         * @brief scalar product between a matrix and a real numeric value
         * 
         * @param scalar : any n C R
         */
        inline void for_scalar_product(const int& scalar){
            for(size_t i{0}; i < rows; ++i){
                for(size_t j{0}; j < cols; ++j){
                    items.at(i).at(j) *= scalar;
                }
            }
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
         * @brief Simple method that prints a matrix. The first code snippet allows to print matrix using rows as index
         * The second one allows the same thing, but using columns as index to print the matrix
         * 
         */
        inline void print() const{
            //rows
            for(size_t i{0}; i < rows; ++i){
                for(size_t j{0}; j < cols; ++j){
                    cout<<items.at(i).at(j) << " ";
                }
                cout<<"\n";
            }
            cout<<"\n";

            //columns
            /*for(size_t i{0}; i < cols; ++i){
                for(size_t j{0}; j < rows; ++j){
                    cout<<items.at(j).at(i) << " ";
                }
                cout<<"\n";
            }*/
        }

};

int main(int argc, char const *argv[])
{                                                                   
    
}   