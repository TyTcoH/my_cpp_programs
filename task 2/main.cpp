// Шомахов Идар СКБ 173 Задача 0
#include <iostream>
#include "Ring.h"
#include <cassert>

int main() {
    Ring obj1(4,3);
    Ring obj2(4,4);
    std::cout << (obj1+obj2).getValue()<<std::endl;
    std::cout << (obj1.inverse()*obj1).getValue()<<std::endl;
    std::cout << (-obj1).getValue();
    return 0;
}