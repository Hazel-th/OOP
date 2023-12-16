#include "Vector.h"

namespace MyVector{



template<typename T, typename Allocator> Vector<T, Allocator>::Vector(){
    this->size = 0;
    this->capacity = 0;
    this->data = nullptr;
}


template<typename T, typename Allocator> Vector<T, Allocator>::Vector(int size){
    this->size = 0;
    this->capacity = size;
    this->data = this->allocator.allocate(size);
}


template<typename T, typename Allocator> Vector<T, Allocator>::Vector(const Vector<T, Allocator > &v){
    this->size = v.size;
    this->capacity = this->size;       
    this->data = this->allocator.allocate(size);
    for (int i = 0; i < v.size(); ++i){
        this->data[i] = v[i];
    }
}


template<typename T, typename Allocator> Vector<T, Allocator>::Vector(const Vector<T, Allocator> &&v){
    this->size = v.size;
    this->capacity = this->size;
    this->data = v.data;
    v.data = nullptr;
}


template<typename T, typename Allocator> T Vector<T, Allocator>::operator[](int index){
     if (index < 0 || index >= this->size){
        throw  std::out_of_range("Index out of range");
    }
    return this->data[index];
}

template<typename T, typename Allocator> int Vector<T, Allocator>::getSize(){
    return this->size;
}

template<typename T, typename Allocator> void Vector<T, Allocator>::push_back(T element){
    if (this->capacity == 0){
        this->capacity = 1;
        this->size = 0;
        this->data = this->allocator.allocate(this->size);
    }

    if (this->size == this->capacity){
        this->capacity *= 2;
        this->reserve(this->capacity);
    }
            
    this->data[size] = element;
    this->size++;
}

template<typename T, typename Allocator> void Vector<T, Allocator>::reserve(int newCapacity){
    if (newCapacity > this->capacity){
        T* newData = this->allocator.allocate(size);
        for (int i = 0; i < this->size;++i){
            newData[i] = this->data[i];
        }
        this->allocator.deallocate(this->data, this->capacity);
        this->data = newData;
    }
}

template<typename T, typename Allocator>  VectorIterator<Vector<T, Allocator>> Vector<T, Allocator>::begin(){
    return Iterator(this->data);
}

template<typename T, typename Allocator>  VectorIterator<Vector<T, Allocator>> Vector<T, Allocator>::end(){
    return Iterator(this->data + this->size);
}

template<typename T, typename Allocator>  const VectorIterator<Vector<T, Allocator>> Vector<T, Allocator>::cbegin()const{
    return  Iterator(this->data);
}

template<typename T, typename Allocator> const VectorIterator<Vector<T, Allocator>> Vector<T, Allocator>::cend() const{
    return  Iterator(this->data + this->size);
}

template<typename T, typename Allocator>  Vector<T, Allocator>::~Vector(){
   allocator.deallocate(this->data, this->capacity);
}



}