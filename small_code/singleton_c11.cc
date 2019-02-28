#include <iostream>
#include <string>
#include <atomic>
#include <mutex>

using namespace std;

template <typename T>
class SingletonFactory{
public:
    static T* GetInstance()
    {
        T* temp = s_Instance.load();
        if(temp == nullptr)
        {
            temp = new T;
            s_Instance.store(temp);
        }
            return temp;

    }

protected:
    SingletonFactory<T>(){}
    ~SingletonFactory<T>(){}

private:
    static std::atomic<T*> s_Instance;
    static std::mutex m_Mutex;

    SingletonFactory<T>(const SingletonFactory<T>&);
    const SingletonFactory<T>& operator=(const SingletonFactory<T>&);
};

template <typename T>
std::atomic<T*> SingletonFactory<T>::s_Instance;

template<typename T>
std::mutex SingletonFactory<T>::m_Mutex;

class Test: public SingletonFactory<Test>{
public:
    void Func(){
        static int i = 0;
        cout <<"Test Singleton : " << i << endl;
        ++i;
    }

    friend class SingletonFactory<Test>;

private:
    Test() = default;
};

int main(int argc, char const *argv[])
{
    Test::GetInstance()->Func();

    return 0;
}


