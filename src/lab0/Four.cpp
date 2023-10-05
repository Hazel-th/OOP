#include <iostream>
#include <exception>
#include <stdexcept>
#include "Four.h"



Four::Four() : _size {0}, _array {nullptr}{}

Four::Four(const size_t &n, unsigned char t){
    if (t > '3' or t < '0'){
        throw std::invalid_argument("wrong data");
    }
    _array = new unsigned char[n];
    for (int i = 0; i < n; i++){
        _array[i] = t;
    }
    _size = n;
}
Four::Four(const std::initializer_list< unsigned char> &t){
    _array = new unsigned char[t.size()];
   
    int i = t.size() - 1;
    for (auto c: t){
        
        if (c > '3' || c < '0'){
            throw std::invalid_argument("wrong data");
        }
        _array[i] = c;
        i--;
    }
    _size = t.size();

}
Four::Four(const std::string &t){
    _array = new unsigned char[t.size()];
    for (int i = 0; i < t.size(); i++){
        if (t[i] > '3' or t[i]<'0'){
            throw std::invalid_argument("wrong data");
        }
        _array[t.size()-1-i] = t[i];
    }
    _size = t.size();
}

Four::Four(const Four& other){
    _size = other._size;
    _array = new unsigned char[other._size];
    for (int i = 0; i <other._size; i++){
        _array[i] = other._array[i];
    }
}

Four::Four(Four &&other) noexcept{ 
    this->_size = other._size;
    this->_array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Four::~Four() noexcept{
    if (_size >0){
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

int Four::getSize(){
    return _size;
}

unsigned char* Four::getArray(){
    return _array;
}

Four Four::operator+(const Four& other){
    int ost = 0;
    Four res (std::max(_size, other._size)+1, '0');
    if (this->_size > other._size){
        for (size_t i = 0; i < other._size; i++){
            res._array[i] = (((this->_array[i]-'0')+(other._array[i] - '0') + ost)%4)+'0';
            ost = ((this->_array[i]-'0')+(other._array[i] - '0') + ost)/4;
        }
        for (size_t i = other._size; i < this->_size; i++){
            res._array[i] = (((this->_array[i]-'0') + ost)%4)+'0';
            ost = ((this->_array[i]-'0') + ost)/4;
        }
    }
    else{
        for (size_t i = 0; i < this->_size; i++){
            res._array[i] = (((this->_array[i]-'0')+(other._array[i] - '0') + ost)%4)+'0';
            ost = ((this->_array[i]-'0')+(other._array[i] - '0') + ost)/4;
        }
        for (size_t i = this->_size; i < other._size; i++){
            res._array[i] = (((this->_array[i]-'0') + ost)%4)+'0';
            ost = ((this->_array[i]-'0') + ost)/4;
        }
    }
    for (int i = res._size-1; i > 0; --i){
        if ( res._array[i] == '0'){
            res._size--;
        }
        else{
            break;
        }
    }
    return res;
}


bool Four::less(const Four& other) const{
    if(this->_size < other._size){
        return true;
    }
    if(this->_size > other._size){
        return false;
    }
    for (int i = this->_size - 1; i >=0; i--){
        if (this->_array[i] < other._array[i]){
            return true;
        }
        if (this->_array[i] > other._array[i]){
            return false;
        }
    }
    return false;
}

bool Four::more(const Four& other) const{
    if(this->_size < other._size){
        return false;
    }
    if(this->_size > other._size){
        return true;
    }
    for (int i = this->_size - 1; i >=0; i--){
        if (this->_array[i] < other._array[i]){
            return false;
        }
        if (this->_array[i] > other._array[i]){
            return true;
        }
    }
    return false;
}

Four Four::operator-(const Four& other){
    if (this->less(other)){
        throw std::logic_error("first < second");
    }
    int zaim = 0;
    for (int i = 0; i < other._size; i++){
        int dif = (int)(_array[i] - '0') - (int)(other._array[i] - '0') - zaim;
        if (dif < 0){
            zaim = 1;
            dif += 4;
        }
        else{
            zaim = 0;
        }
        _array[i] = dif + '0';
    }

    for (int i =this->_size-1; i > 0; --i){
        if (this->_array[i] == '0'){
           this->_size--;
        }
        else{
            break;
        }
    }
    return *this;
}

bool Four::equal(const Four& other){
    if (this->_size != other._size){
        return false;
    }
    else{
        for (size_t i = 0;  i < this->_size; i++){
            if (this->_array[i] != other._array[i]){
                return false;
            }
        }
        return true;
    }
}

