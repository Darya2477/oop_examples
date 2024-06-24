#include <iostream>

//полиморфизм - один интерфейс и множество реализаций этого интерфейса

//полиморфная структура - та структура, у которой есть хотя бы одна полиморфная функция
//для каждой полиморфной струтктуры или класса компилятор создает таблицу виртуалных функций
//в таблице виртуальных функций функции хранятся в порядке их объявления в классе
//если в классе наследнике метод не переопределен, то в таблице виртуалиных методов этого класса, останется не перезатертой виртуальная функция базового класса, и вызовется именно функция базового класса

//IFigure = 0x00AA00
// --------
// draw() = 0x00BB00 (draw_impl())

//Square = 0x00AA04
// ---------
// draw() == 0x00BB04 (draw_impl())

//Rectangle = = 0x00AA08
// ---------
// draw() = = 0x00BB08 (draw_impl())

//Line = = 0x00AA0B
// ---------
//draw() = = 0x00BB0B (draw_impl())

// NVI - NON NIRTUAL INTERFACE - обрабляем виртуальный метод невиртуальным


struct IFigure
{
    //без virtual всегда бы вызывался метод базового класса,
    //IFigure
    //IFigure
    //IFigure
    
    //с virtual вызываются переопределнные методы наследников
    //square
    //rectangle
    //line
    // virtual void draw() 
    // {
    //     std::cout << "IFigure" << std::endl;
    // }
    IFigure(){ //vfpt = 0x00AA00; (компилятор связывает указатель на таблицу виртуальных функций с самой таблицей)
        std::cout << "IFigure" << std::endl;
    }

    virtual ~IFigure(){ //производные объекты могут быть корректно удалены через указатель на базовый класс благодаря виртуальному деструктору
        std::cout << "~IFigure" << std::endl;
    }

    // IFigure()
    // {
    //     draw(); // -> pure virtual function called (вызов виртуальной функции в констуркторе через NVI)
    // }

    //virtual void draw() = 0; //0x00BB00; //чисто виртуалтная функция, должна быть определена в наследнике, нельзя создать объект такого класса

    void draw()
    {
        draw_impl();
    }

    private:
        virtual void draw_impl() = 0; //наследники могут переопределить приватный виртуальный метод
        void* vfpt; //указатель на таблицу виртуальных функций (добавляется компилятором)
};

struct Square: IFigure
{

    Square(){ //vfpt = 0x00AA04;
        std::cout << "Square" << std::endl;
    }

    ~Square(){
        std::cout << "~Square" << std::endl;
    }
    // void draw() override //0x00BB04;
    // {
    //     std::cout << "square" << std::endl;
    // }
        void draw_impl() override //0x00BB04;
    {
        std::cout << "square" << std::endl;
    }
};

struct Line: IFigure
{
    Line(){ //vfpt = 0x00AA0B;
        std::cout << "Line" << std::endl;
    }

    ~Line()
    {
          std::cout << "~Line" << std::endl;
    }
    // void draw() override //0x00BB0B;
    // {
    //     std::cout << "line" << std::endl;
    // }
        void draw_impl() override //0x00BB0B;
    {
        std::cout << "line" << std::endl;
    }
};

struct Rectangle: IFigure
{

    Rectangle(){ //vfpt = 0x00AA08;
      std::cout << "Rectangle" << std::endl;
    }

    ~Rectangle()
    {
        std::cout << "~Rectangle" << std::endl;
    }
    // void draw() override //0x00BB08;
    // {
    //     std::cout << "rectangle" << std::endl;
    // }
        void draw_impl() override //0x00BB08;
    {
        std::cout << "rectangle" << std::endl;
    }
};

int main()
{
    constexpr size_t FIGURES_SIZE = 3u;
    //auto figures[FIGURES_SIZE] = {Square(), Rectangle(), Line()};
    //через указатель на базовый класс вызывается переопределенный метод(указатель на базовый класс - статический тип, за этим типом скрыты динамический типы, которые наследуют базовый класс)
    IFigure* figures[FIGURES_SIZE] = {new Square(), new Rectangle(), new Line()};

    for (size_t i = 0u; i < FIGURES_SIZE; ++i){

        //идем в таблицу виртуальных функций каждого объекта
        figures[i]->draw();
        delete figures[i];
    }


    int value = 0; //статический тип
    int8_t* ptr = (int8_t*)&value; //динамический тип, так как указывает не на однобайтовую переменную, а 4-байтовую

    return 0;
}