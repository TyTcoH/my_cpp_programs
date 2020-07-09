// Идар Шомахов СКБ173. Задача 11.
#include <iostream>
int main() {
    bool num,NUM; // Переменные для проверки на 2 цифры в скобке
    char a,number,ans; // a - вх. данные, number - сохранение цифр, ans - ответ
    int o,max; // o - вложенность, max - максимальная вложенность
    o=max=0;
    num=NUM=false;
    std::cout << "Input data:  \n";
    while (std::cin >> a) {
        if (a != ')' && a != '(' && (a < '0' || a > '9')) {  // Коды цифр идут подряд
            std::cerr << "ERROR!!! WRONG SYMBOLS \n"; // Проверка символов.  Используем cerr для вывода ошибок.
            return 1; // Каждой ошибке присвоен свой номер
        }
        if (a == '(') {
            ++o;      // Можно было использовать и постфиксную форму
            num=false;
        }
        if (a == ')') {
            --o;
            num=false;
        }
        if (o < 0) {
            std::cerr << "ERROR!!! BRACKETS UNPAIRED \n"; // Чтобы программа не работала при таких скобках - )(
            return 2;
        }
        if(a >= '0' && a <= '9' && num == false) {
            number=a;
            num=true; // Запоминаем что в этой скобке уже есть цифра
        } else {
            if(num == true) {
                std::cerr << "ERROR!!! 2 NUMBERS IN BRACKETS\n"; // Проверка на 2 цифры в скобках
                return 3;
            }
        }
        if(o > max && num == true) {
            ans=number;
            max=o;
            NUM=true;
        }
    }
    if( o == 0 && NUM == true  ) { // если o равно 0 - все скобки парные
        std::cout << "Answer:  " << ans <<"\n";
    } else {
        if( NUM == false ) {
            std::cerr << "ERROR!!! NO NUMBERS OR BRACKETS\n"; // Проверка на отсутствие цифр
            return 4;
        } else {
            std::cerr << "ERROR!!! BRACKETS UNPAIRED.\n"; // Если левых скобок больше чем правых
            return 5;
        }
    }
    return 0;
}
