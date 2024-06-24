//перегрузка функции
void print(int value) {}
void print(bool value) {}
void print(const char* str) {}

extern "C" void print_text(const char* str) {} //запрет мэнгирования имен

int main()
{
    print(100);
    print(true);
    print("text");
}

// МЭНГЛИРОВАНИЕ ИМЕН КОМПИЛЯТОРОМ
// dasha@Dasha-lubyasha:~/projects/oop_examples$ g++ -c incapsulation_4.cpp -o incapsulation.o
// dasha@Dasha-lubyasha:~/projects/oop_examples$ objdump --syms incapsulation.o

// incapsulation.o:     формат файла elf64-x86-64

// SYMBOL TABLE:
// 0000000000000000 l    df *ABS*  0000000000000000 incapsulation_4.cpp
// 0000000000000000 l    d  .text  0000000000000000 .text
// 0000000000000000 l    d  .rodata        0000000000000000 .rodata
// 0000000000000000 g     F .text  000000000000000e _Z5printi
// 000000000000000e g     F .text  0000000000000010 _Z5printb
// 000000000000001e g     F .text  000000000000000f _Z5printPKc
// 000000000000002d g     F .text  000000000000000f print_text
// 000000000000003c g     F .text  0000000000000032 main