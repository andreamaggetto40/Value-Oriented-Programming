#include "collection.hpp"

template<typename T>
class List : public Collection{
    public:
        virtual T& get(unsigned int index) const = 0;
};