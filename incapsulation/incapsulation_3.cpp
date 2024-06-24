#include <iostream>

struct Data{
    explicit Data(int value): m_value(value) //запрет неявного создания объекта через конструктор класса(только для конструктора с одним параметром)
    {
        std::cout << "Data" << std::endl;
    }

    int get_value() const{
        return m_value;
    }

    ~Data()
    {
        std::cout << "~Data" << std::endl;
    }

    private:
    int m_value;
};

void func(Data data){

};

int main()
{
    // Data data(10);
    // int value  = data.get_value();

    // Data* data = new Data(10);
    // delete data;

    //func(10); //приведет к вызову конструктора Data(implicit)
    func(Data(10)); //анонимный объект
    
    return 0;
}