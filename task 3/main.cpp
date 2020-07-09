#include <iostream>
#include <array>
#include "transformation.h"

template<typename Fn>
void alg(Fn functor) {
    char input = '\0';
    for (std::size_t i = 0; i < 10; i++) {
        std::cin >> std::noskipws >> input;
        std::cout << functor(input);
    }
}


int main() {

    std::array<char,3> a{{"12"}};
    std::cout << static_cast<int>('1');
    trans::Trans tr;
    tr.transposition(a);
    alg(a);
}
