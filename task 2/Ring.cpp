#include <iostream>
#include "Ring.h"
#include <cassert>
#include <cstdint>

Ring::Ring(std::uint32_t _n, std::int32_t _value) {
    n=_n;
    assert(n > 0);
    assert(n < 32);
    value=_value%(1<<n);
}

Ring Ring::operator-()
{
    Ring res(n,((1<<n)-value)%(1<<n));
    return res;
}

Ring Ring::operator*(Ring right) {
    assert (n==right.n);
    Ring res(n,(right.value*value)%(1<<n));
    return res;
}
Ring Ring::operator+() {
    return *this;
}

Ring Ring::operator+(Ring right) {
    assert(n==right.n);
    Ring res(n,(right.value+value)%(1<<n));
    return res;
}

Ring Ring::operator-(Ring right) {
    return *this+(-right);
}

Ring Ring::inverse(){
    std::int32_t x, y;
    Ring res(n,0);
    if(gcd(value,1<<n, x, y)!=1)
        return res;

    res.value=x;
    if(res.value<0)
        res.value+=1<<n;

    return res;

}
std::int32_t Ring::gcd (std::int32_t a, std::int32_t b, long long int x, std::int32_t & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    std::int32_t x1, y1;
    std::int32_t d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

std::int32_t Ring::getValue(){
    return value;
}
