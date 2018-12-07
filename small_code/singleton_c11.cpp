#include <iostream>
#include <string>
#include <atomic>
#include <mutex>

using namespace std;

template <typename T>
class SingletonFactory
{
public:
    // DCLP + std::atomic 实现单例线程安全+原子操作
    static T* GetInstance()
    {
        T* Temp = s_Instance.load();
        if (Temp == nullptr)
        {
            std::lock_guard<std::mutex> lock(m_Mutex);
            Temp = s_Instance.load();
            if (Temp == nullptr)
            {
                // 缺陷：只能调用默认构造函数
                // 是否在实例的时候, 有语法可以指定具体调用那个构造函数. 或者通过传入具体实例参数, 例如参数列表, 来让编译器自己确定调用的构造函数.
                Temp = new T;
                s_Instance.store(Temp);
                
            }
        }

        return Temp;
    }

protected:
    SingletonFactory<T>() { }
    ~SingletonFactory<T>() { }

private:
    static std::atomic<T*> s_Instance;
    static std::mutex m_Mutex;

    // 父类禁止拷贝操作, 这样子类继承也会默认禁止拷贝操作
    SingletonFactory<T>(const SingletonFactory<T>&);
    const SingletonFactory<T>& operator=(const SingletonFactory<T>&);
};

template <typename T>
std::atomic<T*> SingletonFactory<T>::s_Instance;
template <typename T>
std::mutex SingletonFactory<T>::m_Mutex;

class Test : 
    public SingletonFactory<Test>
{
public:

    void Func()
    {
        static int i = 0;
        cout << "Test Singleton: " << i << endl;
        i++;
    }
    
    // 工厂类友元化, 这样工厂类才可以调用具体类的构造函数.
    friend class SingletonFactory<Test>;
    //Test(const Test& t);
private:
    // 构造函数私有化, 拒绝外部通过构造函数创建实例.
    //Test() = delete;
};

int main()
{
    Test::GetInstance()->Func();

    //Test t(*Test::GetInstance());

    // Test t;  禁止不通过单例工程创建类对象
    // t.Func();

    return 0;
}