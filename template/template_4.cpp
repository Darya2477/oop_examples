#include <iostream>

template <typename T>
void print(T value) {}

// то же самое что и фунция void print(int value)
// template<>
// void print<int>(int value) {}

//перегруженная функция будет всегда приоритетнее шаблонной
void print(int value) {}

int main()
{
    //вызовется перегруженная функция
    print(100);
    //вызовется шаблонная функция, где T - short
    print((short)100);
    return 0;
}