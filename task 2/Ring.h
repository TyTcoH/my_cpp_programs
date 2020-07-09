#ifndef HOMEWORK_RING_H
#define HOMEWORK_RING_H
#include <cstdint>


class Ring {
public:
    Ring( std::uint32_t _n, std::int32_t _value);
    Ring operator+(Ring right);
    Ring operator-();
    Ring operator-(Ring right);
    Ring operator*(Ring right);
    Ring operator+();
    Ring inverse();
    std::int32_t getValue();
private:
    std::int32_t gcd(std::int32_t a, std::int32_t b, long long int x, std::int32_t& y);
    std::uint32_t value;
    std::uint32_t n;

};


#endif //HOMEWORK_RING_H
