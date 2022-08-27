#include <vector>
#include <iostream>
#include "collection.hpp"

using std::vector; 

template<typename T>
class ArrayList : public Collection{
    vector<T> items{};
    
    public:
        ArrayList(){};
        ArrayList(const size_t& initial_size){
            items.resize(initial_size);
        }
        void add(const T& item) const{
            items.add(item);
        }
        void clear() const{
            for(; items.size(); items.pop_back());
        }
        bool equals(const ArrayList<T>& to_compare) const{
            bool check{true};
            if(items.size() != to_compare.items.size()) check = false;
            else{
                if(items == to_compare.items) check = true;
                else{
                    for(size_t i{0}; i < items.size() and check; ++i){
                        check &= (items.at(i) == to_compare.items.at(i));
                    }
                }
            }
            return check;
        }
        bool contains(const T& item) const{
            bool check{false};
            for(size_t i{0}; i < items.size() and !check; ++i){
                check |= (items.at(i) == item);
            }
            return check;
        }
        bool is_empty() const{
            return !items.size() ? true : false;
        }
        size_t size() const{
            return items.size();
        }
};

