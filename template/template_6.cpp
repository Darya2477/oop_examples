#include <iostream>

struct NonCopyable
{
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = default;
    NonCopyable& operator = (const NonCopyable&) = delete;
};

template <typename Derived>
struct Singleton: private NonCopyable
{
    static Derived& get_instance(){
        static Derived instance;
        return instance;
    };
    protected:
        Singleton() = default;

};

struct FileManager: public Singleton<FileManager>{};
struct MemoryManager: public Singleton<MemoryManager>{};
struct SoundManager: public Singleton<SoundManager>{};



// struct FileManager: private NonCopyable
// {
//     static FileManager& get_instance(){
//         static FileManager instance;
//         return instance;
//     };
//     private:
//         FileManager() = default;

// };

int main()
{
    //один и тот же объект
    // FileManager& m1 = FileManager::get_instance();
    // FileManager& m2 = FileManager::get_instance();
    return 0;
}