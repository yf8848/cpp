#include <thread>
#include <atomic>
#include <iostream>
#include <unistd.h>

using namespace std;
std::atomic_flag lock=ATOMIC_FLAG_INIT;

void f(int n)
{
  while (lock.test_and_set(std::memory_order_acquire))  //尝试获得锁
  {
    /* code */
    std::cout << "Waiting from thread" <<n<< '\n';
  }
  std::cout << "thread "<<n <<" start working"<< '\n';
}

void g(int n)
{
  std::cout << "thread "<<n<<" is going to start." << '\n';
  lock.clear();
  std::cout << "thread "<<n <<" start working"<< '\n';
}

int main(int argc, char const *argv[]) {
  auto i = lock.test_and_set();
  std::cout << i << '\n';

  thread t1(f,1);
  thread t2(g,2);

  t1.join();
  usleep(100);
  t2.join();
  return 0;
}

// 编译选项： g++ -std=c++11 6-3-3.cpp -lpthread
