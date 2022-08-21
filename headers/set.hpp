#include <vector>
#include <iostream>
using std::cout; using std::endl; using std::vector; using std::string;

template<typename T>
class custom_set{
    std::vector<T> the_set;

    void remove_doubles(){
        for(size_t i{0}; i < the_set.size(); ++i){
            for(size_t j{0}; j < the_set.size(); ++j){
                if(j != i and (the_set.at(j) == the_set.at(i))){
                    the_set.erase(the_set.begin() + j);
                    --j;
                }
            }
        }
    };

    public:
        custom_set(std::vector<T> items);



        void print();

        T operator[](size_t index);
        custom_set<T> operator=(custom_set<T> to_copy);
};

template<typename T>
custom_set<T>::custom_set(vector<T> items){ 
    for(auto i : items) the_set.push_back(i);

    remove_doubles();
}

template<typename T>
void custom_set<T>::print(){    
    for(auto i : the_set) cout<<i<<endl;
}

template<typename T>
T custom_set<T>::operator[](size_t index){  
    if(index >= 0){
        return the_set.at(index);
    }
}

template<typename T>    
custom_set<T> custom_set<T>::operator=(custom_set<T> to_copy){
    if(!the_set.size() and to_copy.the_set.size()){
        for(auto i : to_copy.the_set) the_set.push_back(i);
    }
}