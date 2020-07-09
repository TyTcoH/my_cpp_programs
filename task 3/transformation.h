#ifndef UNTITLED11_TRANSFORMATION_H
#define UNTITLED11_TRANSFORMATION_H

#include <array>
#include <iostream>
#include <gsl/span>
namespace trans {
    class Trans {
    private:
        std::array<char, 256> arr{};
    public:
        Trans();

        const char operator()(const char &a) const;

        void transposition(gsl::span<char,3> a);
    };

    Trans::Trans() {
        for (std::size_t i = 0; i < 256; ++i) {
            arr[i] = static_cast<char>(i);
        }

    }

    const char Trans::operator()(const char &a) const {
        return arr[static_cast<int>(a)];
    }

    void Trans::transposition(gsl::span<char,3> a) {
        char character = a[0];
        arr[static_cast<int>(a[0])] = arr[static_cast<int>(a[1])];
        arr[static_cast<int>(a[1])] = character;
    }


}

#endif //UNTITLED11_TRANSFORMATION_H
