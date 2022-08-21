#include <vector>
#include <iostream>

using std::vector; using std::cout; using std::endl;

template<typename T>
class list_vect{
    vector<T> items{};

    public:
        list_vect();
        ~list_vect();

        size_t size() const;
        void print() const;
        T& get(unsigned index);
        bool is_empty() const;
        void append(T item);
};

template<typename T>
list_vect<T>::list_vect(){}

template<typename T>
inline list_vect<T>::~list_vect(){cout<<"Destructor properly called!"<<endl;}

template<typename T>
size_t list_vect<T>::size() const{
    return items.size();
}

template<typename T>
bool list_vect<T>::is_empty() const{
    return !size();
}

template<typename T>
void list_vect<T>::print() const{
    for(T it : items) cout<<it<<endl;
}

template<typename T>
T& list_vect<T>::get(unsigned index){
    if(index < 0 or index >= size()) throw "error: index not found";
    else{
        return items.at(index);
    }
}

template<typename T>
void list_vect<T>::append(T item){ 
    items.push_back(item);
}

