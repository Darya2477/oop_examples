#include <iostream>

struct IFigureDynamic
{
    virtual void draw() = 0;
    virtual ~IFigureDynamic() = default;
};

struct CircleDynamic: IFigureDynamic
{
    void draw() override {};
};

//CRTP(Curiously recurring template pattern)

    // 1.Наследовались от интерфейса, параметризуя его собой.
    // 2.Для того, чтобы функции-реализации не попали в интерфейс пользователя, объявляем их в блоке private.
    // 3.Для того, чтобы класс интерфейса видел функции-реализации, объявляем его как friend.

template<typename Derived>
struct IFigureStatic
{
    void draw(){
        static_cast<Derived*>(this)->draw_impl();
    };
};

struct CircleStatic: IFigureStatic<CircleStatic>
{
    void draw_impl(){};
};


int main(){

    //реализация динамического полиморфизма
    {
        CircleDynamic c;
        IFigureDynamic& d = c;
        //вызовется метод производного класса
        d.draw();
    }

    //реализация статического полиморфизма
    {
        CircleStatic c;
        IFigureStatic<CircleStatic>& f = c;
        //вызов метода производного класса (draw_impl)
        f.draw();
    }
    return 0;
}