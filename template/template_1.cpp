#include <iostream>

//шаблоны работают в процессе компиляции, компилятор подставляет тип и создает эту функцию
template<typename T>
void print(const T& data)
{
    std::cout << "- " << data << " -" << std::endl;
}


int main()
{
    print("data");
    print(100);
    print(100.0f);
    return 0;
}