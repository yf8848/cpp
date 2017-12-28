#include <iostream>
#include <stdio.h>
using namespace std;
class HasPtrMem{
public:
  HasPtrMem():d(new int(0)){printf("%p\n", d);}
  HasPtrMem(HasPtrMem& h):
    d(new int(*h.d))
    {
      std::cout << "copy constructor" << '\n';
      printf("%p\n", d);
    }

  ~HasPtrMem(){delete d;}

  int* d;
};

int main(int argc, char const *argv[]) {
  HasPtrMem a;
  HasPtrMem b(a);

  std::cout << *a.d << '\n';
  std::cout << *b.d << '\n';
  return 0;
}
