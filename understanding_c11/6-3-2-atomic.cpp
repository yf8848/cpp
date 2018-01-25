#include <atomic>
#include "thread"
#include <iostream>

using namespace std;

atomic<long long> total {0};

void func(int) {
  /* code */
  for (long long i =0;i<100000000LL;++i)
  {
    total+=i;
  }
}

int main(int argc, char const *argv[]) {
  thread t1(func,0);
  thread t2(func,0);

  t1.join();
  t2.join();
  std::cout << total << '\n';
  return 0;
}

// g++ -std=c++11 6-3-2-atomic.cpp -lpthread
