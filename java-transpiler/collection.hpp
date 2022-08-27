template<typename T>
class Collection{
    public:
        virtual void add(const T& item) const = 0;
        virtual void clear() const = 0;
        virtual bool contains(const T& item) = 0;
        virtual bool equals(const T& item) const = 0;
        virtual bool is_empty() const = 0;
        virtual size_t size() const = 0;
};