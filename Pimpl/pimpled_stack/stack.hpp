template<typename T>
class stack{
    struct impl;
    impl* pimpl;

    public:
        stack();
        stack(const size_t& size, const T& init);
        const size_t size() const;
        void print_stack() const;
};