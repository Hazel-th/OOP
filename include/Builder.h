#pragma once
#include "Four.h"
#include <iostream>

class Builder{
    private:
        Four obj;
    public:
        Builder();
        Builder& size(int val);
        Builder& arr(unsigned char* t);
        Four build();
};