#pragma once
#include <string>


class Four{
private:
    unsigned char* _array;
    int _size;

public:
    Four();
    Four(const size_t &n, unsigned char t);
    Four(const std::initializer_list< unsigned char> &t);
    Four(const std::string &t);
    Four(const Four& other);
    Four(Four&& other) noexcept;
    virtual ~Four() noexcept;

    unsigned char* getArray();
    int getSize();
    Four operator+(const Four& other);
    Four operator-(const Four& other);
    bool equal(const Four& other);
    bool more(const Four& other) const;
    bool less(const Four& other) const;

    friend class Builder;
};