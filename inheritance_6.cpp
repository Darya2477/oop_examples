#include <iostream>

struct SuperBaseData{
    int super_base_value = 0;
}

struct BaseData1: virtual SuperBaseData{
    int base_value_1 = 2;
}

struct BaseData2: virtual SuperBaseData{
    int base_value_2 = 2;
}

struct Data: BaseData1, BaseData2{
    int value = 3;
}

        //   SPD 
        //  /  \ 
        // BD1  BD2
        //  \   /
        //    D

// BaseData1
// | super_base_value(0) | base_value_1(2) |   


// BaseData2
// | super_base_value(0) | base_value_2(2) |  

// Data
// | super_base_value(0) | base_value_1(2) | super_base_value(0) | base_value_2(2) | value(3) |

// Data(если наследование виртуальное)
// | vbptr | base_value_1(2)| vbptr | base_value_2(2) | value(3) | super_base_value(0) |

int main()
{
    Data data;
    //data.super_base_value = 100; - ошибка компилляции, так как компилятор не знает, к какому объекту обратиться
    //date.BaseData1::super_base_value = 100;
    //date.BaseData2::super_base_value = 200;

    //если хотим обращаться к полю, как к единому целому используем virtual наследование
    return 0;
}