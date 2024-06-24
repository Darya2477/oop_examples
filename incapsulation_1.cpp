#include <iostream>

//Функции инкапсуляции:
//1)Использование интерфейсов, без знания особенностей устройства реализации
//2)Доступ пользователя только к заведомо подготовленным для него методам

class Date
{
public:
    void set_day(unsigned int value)
    {
        if (value > 0 && value<=31)
        {
            day = value;
        }
    }

    void set_month(unsigned int value){
        if (value > 0 && value <= 12)
        {
            month = value;
        }
    }

    void set_year(unsigned int value)
    {
        year = value;
    }

    unsigned int get_day() const{
        return day;
    }

    unsigned int get_month() const{
        return month;
    }

    unsigned int get_year() const{
        return year;
    }

private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

int main()
{
    Date d;
    d.set_day(20);
    d.set_month(11);
    d.set_year(1998);

    int day = d.get_day();
    int month = d.get_month();
    int year = d.get_year();

    return 0;
}