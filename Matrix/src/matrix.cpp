#include "matrix.hpp"
/**
 * matrix 
 * @brief: Matrix library implementation
 */
inline matrix::matrix() = default;
inline matrix::matrix(const size_t& rows, const size_t& cols) : rows(rows), cols(cols){
    items = vector<vector<int>>(rows, vector<int>(cols,0));

    srand(time(nullptr));
    for(size_t i{0}; i < rows; ++i){
        for(size_t j{0}; j < cols; ++j){
            items.at(i).at(j) = rand() % 100 + 1;
        }
    }
}
inline matrix::matrix(const matrix& to_copy) : rows(to_copy.rows), cols(to_copy.cols){
    items = to_copy.items;
}
inline vector<int> matrix::get_main_diagonal() const{
    vector<int> output{items.at(0).at(0)};

    for(size_t i{1}; i < rows; ++i){
        output.push_back(items.at(i).at(i));
    }

    return output;
}
inline bool matrix::is_diagonal() {
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
inline matrix matrix::trasposed() const{
    matrix output{cols, rows};

    for(size_t i{0}; i < rows; ++i){
        for(size_t j{0}; j < cols; ++j){
            output.items.at(j).at(i) = items.at(i).at(j);
        }
    }

    return output;
}
inline matrix matrix::identity(int size) const{
    assert(rows == cols);
    matrix output{size,size};

    for(size_t i{0}; i < size; ++i){
        output.items.at(i).at(i) = 1;
    }

    return output;
}
inline matrix matrix::sum(const matrix& to_sum) const{
    assert(rows == to_sum.rows and cols == to_sum.cols);
    matrix output{rows,rows};

    for(size_t i{0}; i < rows; ++i){
        for(size_t j{0}; j < rows; ++j){
            output.items.at(i).at(j) = items.at(i).at(j) + to_sum.items.at(i).at(j);
        }
    }

    return output;
}
inline size_t matrix::get_rows() const{
    return rows;
}
inline size_t matrix::get_cols() const{
    return cols;
}
inline matrix matrix::product(const matrix& to_mul) const{
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
inline int matrix::determinant() const{
    return 0;
}
inline void matrix::for_scalar_product(const int& scalar){
    for(size_t i{0}; i < rows; ++i){
        for(size_t j{0}; j < cols; ++j){
            items.at(i).at(j) *= scalar;
        }
    }
}
inline int matrix::trace() const{
    int output{items.at(0).at(0) + items.at(rows - 1).at(rows - 1)};

    for(int counter{1}, i{1}, j {1}; counter < rows - 1; ++counter, ++i, ++j){
        output += items.at(i).at(j);
    }

    return output;
}
inline bool matrix::is_triangular() const{
    assert(rows == cols);
    bool check{true};

    for(size_t i{0}; i < rows and check; ++i){
        if(!i) check &= items.at(i).at(i);
        else{
            for(size_t j{0}; j < i; ++j){
                check &= !(items.at(i).at(j));
            }
        }
    }

    if(!check){
        check = true; size_t reverse_row{rows - 1};

        for(size_t i{reverse_row}; i >= 0 and check; --i){
            if(!i) check &= items.at(i).at(i);
            else{
                for(size_t j{reverse_row}; j > i; --j){
                    check &= !(items.at(i).at(j));
                }
            }
        }
    }

    return check;
}
inline void matrix::print() const{
    //rows
    for(size_t i{0}; i < rows; ++i){
        for(size_t j{0}; j < cols; ++j){
            cout<<items.at(i).at(j) <<" ";
        }
        cout<<"\n";
    }
    //columns
    /*for(size_t i{0}; i < cols; ++i){
        for(size_t j{0}; j < rows; ++j){
            cout<<items.at(j).at(i) << " ";
        }
        cout<<"\n";
    }*/
};

