#include "BigInteger.h"

BigInteger::BigInteger() {
    size = 1;
    for(int i=0;i<200;i++) data[i] = 0;
}

BigInteger::BigInteger(int num) {
    size=0;
    while(num!=0) {
        data[size] = num%10;
        num/=10;
        size++;
    }
    if(size==0) size=1;
}
BigInteger::BigInteger(const BigInteger &other) {
    size = other.size;
    for(int i=0;i<size;i++) data[i] = other.data[i];
}

const BigInteger BigInteger::operator+(const BigInteger &other) {
    BigInteger b;
    int newSize = std::max(b.size, other.size)+1;
    for(int i=0;i<newSize;i++) {
        b.data[i]+=other.data[i];
        b.data[i+1]+=b.data[i]/10;
        b.data[i]%=10;
    }
    if(b.data[newSize-1]==0) b.size = newSize-1;
    return b;
}

const BigInteger BigInteger::operator+(const int &other) {
    BigInteger b;
    int newSize=0, oth = other;
    for(int i=0;oth!=0;i++) {
        b.data[i]+=oth%10;
        oth/=10;
        b.data[i+1]+=data[i]/10;
        b.data[i]%=10;
        newSize++;
    }
    b.size=std::max(b.size, newSize);
    return b;
}

const BigInteger BigInteger::operator-(const BigInteger &other) {
    BigInteger z;
    for (int ix = 0; ix < (size - 1); ix++) {
        if (ix < (size - 1)) {
            data[ix + 1]--;
            z.data[ix] += 10 + data[ix];
        } else 
                z.data[ix] += data[ix];
        z.data[ix] -= other.data[ix];

        if (z.data[ix] / 10 > 0) {
            z.data[ix + 1]++;
            z.data[ix] %= 10;
        }
    }
    z.size = 200;
    for(int i=0;z.data[i]==0;i--, z.size--);
    return z;
}

const BigInteger BigInteger::operator-(const int &other) {
    BigInteger b(other);
    return (*this)-b;
}

bool BigInteger::operator>(const BigInteger &other) {
    if(size>other.size) return true;
    if(size<other.size) return false;
    int equals = 0;
    for(int i=size-1;i>=0;i--) {
        if(data[i]<other.data[i]) return false;
        equals+=(data[i]==other.data[i]);
    }
    if(equals==size) return false;
    return true;
}

bool BigInteger::operator>(const int &other) {
    BigInteger b(other);
    return (*this)>b;
}

bool BigInteger::operator<(const BigInteger &other) {
    if(size<other.size) return true;
    if(size>other.size) return false;
    int equals = 0;
    for(int i=size-1;i>=0;i--) {
        if(data[i]>other.data[i]) return false;
        equals+=(data[i]==other.data[i]);
    }
    if(equals==size) return false;
    return true;
}

bool BigInteger::operator<(const int &other) {
    BigInteger b(other);
    return (*this)<b;
}

bool BigInteger::operator>=(const BigInteger &other) {
    if(size>other.size) return true;
    if(size<other.size) return false;
    for(int i=size-1;i>=0;i--) {
        if(data[i]<other.data[i]) return false;
    }
    return true;
}

bool BigInteger::operator>=(const int &other) {
    BigInteger b(other);
    return (*this)>=b;
}

bool BigInteger::operator<=(const BigInteger &other) {
    if(size>other.size) return true;
    if(size<other.size) return false;
    for(int i=size-1;i>=0;i--) {
        if(data[i]>other.data[i]) return false;
    }
    return true;
}

bool BigInteger::operator<=(const int &other) {
    int oth = other;
    for(int i=0;oth!=0;i++) {
        if(size>i+1) return false;
        if(data[i]!=oth%10) return false;
        oth/=10;
    }
    return true;
}

bool BigInteger::operator==(const BigInteger &other) {
    if(size!=other.size) return false;
    for(int i=size-1;i>=0;i--) {
        if(data[i]!=other.data[i]) return false;
    }
    return true;
}

bool BigInteger::operator==(const int &other) {
    int oth = other;
    int i = 0;
    while(oth!=0) {
        if(data[i]!=oth%10) return false;
        oth/=10;
        i++;
    }

    return true;
}


std::string BigInteger::getAsString() {
    std::ostringstream sstream;
    for(int i=0;i<size;i++) {
        sstream << data[i];
    }
    return sstream.str();
}
