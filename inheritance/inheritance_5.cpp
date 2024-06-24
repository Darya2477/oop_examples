#include <iostream>

//правило нуля - ничего не нужно писать, если внутри класса расположены поля примитивных типов, либо типов, которые сами корректно управляют своими ресурсами
//правило трех - деструктор + конструткор копирования + оператор копирования


struct SmartPtr
{
    explicit SmartPtr(int* ptr)
    : m_ptr(ptr) {}

    SmartPtr(const SmartPtr& other){
        if (other.m_ptr)
        {
            m_ptr = new int(*other.m_ptr);
        }
    }

    SmartPtr operator = (const SmartPtr& other)
    {
        if (this != &other && other.m_ptr)
        {
            delete m_ptr;
            m_ptr = new int(*other.m_ptr);
        }
        return *this;
    }

    ~SmartPtr()
    {
        delete m_ptr;
    }

    private:
    int* m_ptr;
};

int main()
{
    SmartPtr data_1(new int(10)); //deleted(0x00AABC) -> double free (если не используется конструктор кописрования объекта)
    SmartPtr data_2(data_1);      //deleted(0x00AABC)

    data_2 = data_1; //вызывается оператор присваивания
    return 0;
}