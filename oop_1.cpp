#include <iostream>

typedef struct {
    int* ptr;
}smart_ptr;

smart_ptr smart_ptr_create(int value)
{
    smart_ptr sptr;
    sptr.ptr = (int*) malloc(sizeof(value));
    *(sptr.ptr) = value;
    return sptr;
}

void smart_ptr_destroy(smart_ptr sptr)
{
    free(sptr.ptr);
}

void func()
{
    smart_ptr sptr = smart_ptr_create(100);
    //Если забыть удалить sptr.ptr - то утечка памяти
    smart_ptr_destroy(sptr);

}

//C++ использует идиому RAII(Захват ресурса есть инциализация)

struct SmartPtr{
    SmartPtr(int* ptr){
        m_ptr = ptr;
    }
    ~SmartPtr(){
       delete m_ptr; 
    }
    int* m_ptr;
};

int main(){
    func();

    int* ptr = new int(100);

    //обяхательно вызовется деструктор
    SmartPtr sptr(ptr);

    return 0;
}
