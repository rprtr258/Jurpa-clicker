#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <algorithm>
#include <sstream>
#include <string>

class BigInteger {
    public:
        BigInteger();
        BigInteger(int num);
        BigInteger(const BigInteger &other);
        const BigInteger operator+(const BigInteger &other);
        const BigInteger operator+(const int &other);
        const BigInteger  operator-(const BigInteger &other);
        const BigInteger  operator-(const int &other);
        bool operator>(const BigInteger &other);
        bool operator>(const int &other);
        bool operator<(const BigInteger &other);
        bool operator<(const int &other);
        bool operator>=(const BigInteger &other);
        bool operator>=(const int &other);
        bool operator<=(const BigInteger &other);
        bool operator<=(const int &other);
        bool operator==(const BigInteger &other);
        bool operator==(const int &other);

        std::string getAsString();
    private:
        int data[200];
        int size;
};

#endif
