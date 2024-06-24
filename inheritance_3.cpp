#include <iostream>

struct Data
{
    explicit Data(size_t size)
    : m_size(size), m_buffer(new int[m_size]){} //сначала будет инициализироваться m_buffer, а затем m_size,
                                                //как в порядке указанном в полях (bad alloc)

    ~Data()
    {
        delete[] m_buffer;
    }

    private:
    int* m_buffer;
    size_t m_size;
};


int main(int argc, char** argv)
{
    Data data(10u);
    return 0;
}