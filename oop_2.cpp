#include <iostream>

typedef struct date{
    int day;
    int month;
    int year;
}date;

void print(date* d)
{
    if (!d){
        return;
    }

    printf("%u:%u:%u\n", d->day, d->month, d->year);
}

struct Date{

    //1)при конструировании объекта сначала создадутся поля в указанном порядке
    int day;
    int month;
    int year;
    //2.1)затем вызывается конструктор
    Date(int day_, int month_, int year_){
        //3.1)происходит инициализация полей по порядку
        day = day_;
        month = month_;
        year = year_;
    }

    //2.2) сразу инициализирую значения переменных в момент их создания
    Date(int day_, int month_, int year_): day(day_), month(month_), year(year_){
        //3.2)затем вызывается конструктор
    }

    void print()
    {
        std::cout << day << ":" << month << ":" << year << std::endl;
    }
};

int main(){
    {
    date d;
    d.day = 10;
    d.month = 4;
    d.year = 1998;
    //приходится передавать указатель на структуру 
    print(&d);
    }

    {
    Date d(10,4,1998);
    //передается указатель this на текущий объект
    d.print();
    }

}