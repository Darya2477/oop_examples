#include <iostream>

//частичная специализация

//для всех массивов, у которых размерность не 1024
template<typename T, size_t N>
struct array{


};

//для всех массивов, у которых размерность 1024
template<typename T>
struct array<T, 1024>
{

};

int main(){
    return 0;
}