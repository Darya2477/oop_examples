#include <iostream>

struct Base
{
    void print(int value)
    {
        std::cout << "print_base: " << value << std::endl;
    }

    void print(const std::string& data)
    {
        std::cout << "print_base: " << data << std::endl;
    }
};

struct Derived: Base{
    using Base::print; //отсавляем перегрузку оставшихся методов
    //сокрываю метод базового класса методом производного класса (сокрытие имен)
    void print(int value) 
    {
        std::cout << "print_derived: " << value << std::endl;
    }
};

int main()
{
    Derived derived;
    derived.print(100);
    //derived.print("data"); - ошибка компилляции, так как при сокрытии имени исключается вся перегрузка, то есть мы полностью сокрыли метод, принимающий строку(если нет явного указания использования методов базового класса)
    derived.print("data"); //метод print базового класса
    return 0;
}