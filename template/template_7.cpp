#include <iostream>

//метапрограммирование - заставить код выполняться во время компиляции, т.е. уменьшить время на рантайме
unsigned int factorial(unsigned int value)
{
    if (value == 0 || value == 1)
    {
        return 1;
    }
    else 
    {
        return value * factorial( value - 1 );
    }
};

template<unsigned int N>
struct Factorial
{
    static const unsigned int value = N * Factorial< N - 1 >::value;
};

//ограничение для рекурсии 
template<>
struct Factorial<0>
{
    static const unsigned int value = 1;
};

//ограничение для рекурсии
template<>
struct Factorial<1>
{
    static const unsigned int value = 1;
};

int main(){

    //код работает во время выполнения программы
    const unsigned int res1 = factorial(10);

    //код работает во время компилляциии(сгенерируется 10 функций на этапе компилляции)
    const unsigned int res2 = Factorial<10>::value;
    return 0;
}