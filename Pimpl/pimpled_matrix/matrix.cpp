#include "matrix.hpp"
#include <vector>

using std::vector; using std::cout;

template<typename T>
struct matrix<T>::impl{
    vector<vector<T>> items{};
    size_t rows{0},cols{0};
};

template<typename T>
matrix<T>::matrix(){
    pimpl = new impl{};
}

template<typename T>
matrix<T>::matrix(const size_t& rows, const size_t& cols){
    pimpl = new impl{};
    pimpl->rows = rows;
    pimpl->cols = cols;

    pimpl->items.resize(rows);

    for(size_t i{0}; i < pimpl->rows; ++i){
        pimpl->items.at(i).resize(cols);
    }
}

template<typename T>
matrix<T>::matrix(const matrix<T>& to_copy){
    pimpl = new impl{};
    pimpl->items = to_copy.pimpl->items;
}

template<typename T>
matrix<T>::~matrix(){
    cout << "Destructor called!" <<"\n";
    delete pimpl;
}

template<typename T>
void matrix<T>::print() const{
    for(size_t i{0}; i < pimpl->rows; ++i){
        for(size_t j{0}; j < pimpl->cols; ++j){
            cout << pimpl->items.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}

template<typename T>
T& matrix<T>::at(const size_t& row, const size_t& col){
    if(row < pimpl->rows and col < pimpl->cols){
        return pimpl->items.at(row).at(col);
    }
}

template<typename T>
const T& matrix<T>::at(const size_t& row, const size_t& col) const{
    return at(row,col);
}

template<typename T>
size_t matrix<T>::size() const{
    return pimpl->cols * pimpl->rows;
}

template<typename T>
matrix<T> matrix<T>::reduce(const size_t& row, const size_t& col){
    //assert: row < pimpl->rows and col < pimpl->cols
    matrix<T> new_matrix{pimpl->rows - 1, pimpl->cols - 1};
    size_t new_mat_row{0},new_mat_col{0};

    for(size_t i{0}; i < pimpl->rows; ++i){
        if(i != row - 1){
            for(size_t j{0}; j < pimpl->cols; ++j){
                if(j != col - 1){
                    new_matrix.pimpl->items.at(new_mat_row).at(new_mat_col) = pimpl->items.at(i).at(j);
                    ++new_mat_col;
                }
                ++new_mat_row; 
                new_mat_col = 0;
            }
        }
    }

    return reduce;
}

int main(int argc, char const *argv[])
{

}
