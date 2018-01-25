#include "pthread.h"
#include <iostream>
using namespace std;

volatile long long total = 0;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* func(void*)
{
  long long i;
  for (size_t i = 0; i < 100000000LL; i++) {
    /* code */
    pthread_mutex_lock(&m);
    total+=i;
    pthread_mutex_unlock(&m);
  }
}

int main(int argc, char const *argv[]) {
  pthread_t thread1,thread2;

  if (pthread_create(&thread1,NULL,&func,NULL)) {
    /* code */
    throw;
  }

  if (pthread_create(&thread2,NULL,func, NULL)) {
    /* code */
    throw;
  }

  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);

  std::cout << total << '\n';
  return 0;
}
// g++ 6-3-1-pthread.cpp -lpthread
