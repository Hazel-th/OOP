#include "Builder.h"
#include "Four.h"

Builder::Builder() = default;

Builder& Builder::size(int val){
    obj._size = val;
    return *this;
}

Builder& Builder::arr(unsigned char* t){
    obj._array = new unsigned char [obj._size];

    for (int i = 0; i < obj._size; i++){
        obj._array[obj._size-i-1] = t[i];
    }
    return *this;
}

Four Builder::build(){
    return obj;
}