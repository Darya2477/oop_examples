#include <iostream>

struct Data
{
    void inc()
    {
        value++;
    }

    void print(){

        std::cout << value << std::endl;
        value_mute++;
    }

    void print_const() const{

        std::cout << value << std::endl;
        value_mute++;
    }

    int value = 0;
    mutable int value_mute = 0; //mutable параметры можно менять в const методах ( bad practice )

};

int main()
{
    //не можем менять объект
    const Data d;

    //d.value = 100; - ошибка
    //d.inc(); - ошибка, так как тоже меняет состояние объекта
    //d.print() - ошибка, так как C++ не разбирается меняется ли состояние
                //объекта внутри метода или нет
    d.print_const(); //у константного объекта можно вызвать только константный метод

    return 0;
}