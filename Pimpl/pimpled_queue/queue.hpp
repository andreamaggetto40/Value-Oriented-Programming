template<typename T>
class queue{
    struct impl;
    impl* pimpl;

    public:
        queue();
        queue(const size_t& size, const T& init);
        const size_t size() const;
        void print_queue() const;
};