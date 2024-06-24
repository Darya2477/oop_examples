#include <iostream>

struct BaseData
{
    public:
    BaseData() {std::cout << "BaseData" << std::endl;};
    ~BaseData() {std::cout << "~BaseData" << std::endl;};

    protected:
    int base_value_1 = 1;
    int base_value_2 = 2;
};

struct Data: BaseData
{
    public:
    Data() {std::cout << "Data" << std::endl;};
    ~Data() {std::cout << "~Data" << std::endl;};

    private:
    int value_3 = 3;
};


//base_data                           
//| base_value_1(1) | base_value_2(2) |
// 0x00AA00          0x00AA04         

//data
//| base_value_1(1) | base_value_2(2) |  value_3(3)   |
// 0x00AA00          0x00AA04           0x00AA08


int main()
{
    Data data; 
    BaseData* base_data_ptr = &data;  //up-cast(каст к родителю, указывает на базовую часть объекта)

    std::cout << "///////" << std::endl;

    Data* data_ptr = static_cast<Data*>(base_data_ptr); //down-cast(от указателя на базовый класс скаститься к производной части класса)
    //указатель на базовую часть класса как-бы за собой содержит и производную часть

    std::cout << "///////" << std::endl;

    BaseData base_data_ptr_1;
    Data* data_ptr_1 = static_cast<Data*>(&base_data_ptr_1); //базовый класс не содержит часть производного класса, приведет к неопределенному поведению

    //static_cast при down_cast не проверяет содержится ли производная часть у базового объекта, поэтому это опасно, лучше использовать dynamic_cast

    return 0;
}