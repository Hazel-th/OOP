#pragma once
#include <memory>
#include <iostream>
namespace MyVector {


    template<typename Vector>
    
    class VectorIterator{
        public:
        using ValueType = typename Vector::ValueType;
        using PointerType = ValueType*;
        using ReferenceType = ValueType&;
        public:
        VectorIterator(PointerType ptr){
            this->ptr = ptr;
        }

        VectorIterator& operator++(){
            this->ptr++;
            return *this;
        }


        VectorIterator operator++(int){
            VectorIterator itr = *this;
            ++(*this);
            return itr;
        }

        VectorIterator& operator--(){
            this->ptr--;
            return *this;
        }

        VectorIterator operator--(int){
            VectorIterator itr = *this;
            --(*this);
            return itr;
        }

        ReferenceType operator[](int index){
            return *(this->ptr + index);

        }

        PointerType operator->(){
            this->ptr;
        }

        ReferenceType operator*(){
            return *ptr;
        }

        bool operator==(const VectorIterator& other) const {
            return this->ptr == other.ptr;
        }

        bool operator!=(const VectorIterator& other) const {
            return this->ptr != other.ptr;
        }

        private:
        PointerType ptr;
    };

    
    template<typename T, typename Allocator = std::allocator<T> >
    class Vector{
        public:
        using ValueType = T;
        using Iterator = VectorIterator<Vector<T, Allocator>>;
        public:
        Vector();
        Vector(int size);
        Vector(const Vector<T, Allocator > &v);
        Vector(const Vector<T, Allocator> &&v);
            

        
        T operator[](int index);
        int getSize();
        void push_back(T element);

        void reserve(int newCapacity);
        
        Iterator begin();
        const Iterator cbegin() const;
        Iterator end();
        const Iterator cend() const;
        ~Vector();

        private:
            T* data;
            int size;
            int capacity;
            Allocator allocator;

    };
};