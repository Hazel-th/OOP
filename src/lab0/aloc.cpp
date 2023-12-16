#include <vector>
#include <map>
#include <iostream>

namespace mai
{
    template <class T, size_t BLOCK_SIZE>
    class allocator
    {
    private:
        std::vector<T> memory;
        int capacity;

    public:
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = std::size_t;

        allocator()
        {
            this->capacity = BLOCK_SIZE;
            this->memory.resize(this->capacity);
        }

        ~allocator()
        {
         
        }

        template <typename U>
        struct rebind
        {
            using other = allocator<U, BLOCK_SIZE>;
        };

        T *allocate(size_t n)
        {
            
            if (n > this->capacity){
                throw std::bad_alloc();
            }
            this->capacity-=n;
            return &this->memory[this->memory.size() - capacity -1];
        }

        void deallocate(T *, size_t n)
        {
            
        }

        template <typename U, typename... Args>
        void construct(U *p, Args &&...args)
        {
            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(pointer p)
        {
            p->~T();
        }
    };
}