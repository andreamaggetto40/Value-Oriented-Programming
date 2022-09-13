#pragma once

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
    size_t rows{},cols{};

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
         */
        matrix();
        /** Parametered constructor
         * @brief Construct a new matrix object
         * @param rows : matrix rows
         * @param cols : matrix cols
         */
        matrix(const size_t& rows, const size_t& cols){};
        /** Copy constructor
         * @brief Construct a new matrix object
         * @param to_copy : Matrix to be copied
         */
        matrix(const matrix& to_copy){};
        /**
         * @brief Method to calculate main diagonal of a matrix. 
         * A matrix main diagonal is defined as the values set : (x,y) -> x == y
         * @return Matrix diagonal
         */
        vector<int> get_main_diagonal() const{};
        /**
         * @brief Method to check whether a matrix is diagonal
         * A matrix is diagonal iif for any n,m : n = (x,y), x == y and m = (a,b), a # b -> n # 0 and m = 0
         * @return bool : check whether matrix is diagonal or not.
         */
        bool is_diagonal() {};
        /** Transposition of a matrix
         * @brief Method that builds the transposed matrix, give another one
         * @return matrix : Transposed matrix
         */
        matrix trasposed() const{};
        /**
         * @brief Identity matrix creator method
         * 
         * @param size : Size of the matrix (iif size mod 2 = 0 -> it's possibile to create the identity matrix)
         * @return matrix : Identity matrix
         */
        matrix identity(int size) const{};
        /** 
         * @brief Method to sum two matrix, and outcome the resulted one
         * 
         * @param to_sum : the matrix to add
         * @return matrix : sum matrix
         */
        matrix sum(const matrix& to_sum) const{};
        /**
         * @brief Get the Matrix rows
         * 
         * @return size_t : rows number
         */
        size_t get_rows() const{};
        /**
         * @brief Get the Matrix cols
         * 
         * @return size_t : cols number
         */
        size_t get_cols() const{};
        /**
         * @brief Method that calculates the product matrix
         * 
         * @param to_mul : Matrix to multiply
         * @return matrix : Product matrix
         */
        matrix product(const matrix& to_mul) const{};
        /**
         * @brief Method that calculates the matrix determinant
         * 
         * @return int : Determinant
         */
        int determinant() const{};
        /**
         * @brief scalar product between a matrix and a real numeric value
         * 
         * @param scalar : any n C R
         */
        void for_scalar_product(const int& scalar){};
        /**
         * @brief Method that outputs a matrix trace
         * 
         * @return int: The calculated trace
         */
        int trace() const{};
        /**
         * @brief Method that returns a bool based on whether the matrix is triangular or not
         * It checks if the given matrix is either upper triangular or lower triangular
         * 
         * @return bool: True if triangular, false otherwise
         */
        bool is_triangular() const{};
        /**
         * @brief Simple method that prints a matrix. The first code snippet allows to print matrix using rows as index
         * The second one allows the same thing, but using columns as index to print the matrix
         * 
         */
        void print() const{};
};
