#include <iostream>

//шаблонная структура
//1)
template<typename T>
struct vector
{
    
};

//явная специализация шаблона для вектора булевых значений
//2)
template<>
struct vector<bool>
{

};

//можно явно специализировать указатели, ссылки, массивы, функции и тд
//3)
template<typename T>
struct vector<T*>
{

};

int main()
{
    vector<int> vec_1; //вызовется 1)
    vector<bool> vec_2; //вызовется 2)
    vector<bool*> vec_3; //вызовется 3)
    return 0;
}