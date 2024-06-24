#include <iostream>

// 1-start_engine, 2 - start transmission
// нам не нужно знать в каком порядке вызывать методы
struct Car
{
    void start(){
        start_engine();
        start_transmission();
    }
private:
    void start_engine(){
        std::cout << "engine was started" << std::endl;
    }

    void start_transmission(){
        std::cout << "transmission was started" << std::endl;
    }
};

int main()
{
    Car car;
    car.start();
    

}