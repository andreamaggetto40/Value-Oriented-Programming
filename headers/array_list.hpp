#include <vector>
#include <iostream>

using std::vector; using std::endl; using std::cout; using std::string;

template<typename T>
class ArrayList{
    std::vector<T> Array_List;

    public:
        void add(T item);
        size_t size();
        void print();
};

template<typename T>
size_t ArrayList<T>::size(){
    return this->Array_List.size();
}

template<typename T>
void ArrayList<T>::add(T item){
    Array_List.push_back(item);
}

template<typename T>
void ArrayList<T>::print(){
    for(size_t i{0}; i < Array_List.size(); ++i){
        cout<<Array_List.at(i).to_string() <<endl;
    }
}