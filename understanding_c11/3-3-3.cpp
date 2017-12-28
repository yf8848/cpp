#include <iostream>
using namespace std;

class HasPtrMem{
public:
  HasPtrMem():d(new int(0))
  {
    std::cout << "construct: " <<++n_cstr<< '\n';
  }

  HasPtrMem(const HasPtrMem& h):d(new int(*h.d))
  {
    std::cout << "copystrut:" <<++n_cptr<< '\n';
  }

  ~HasPtrMem()
  {
    delete d;
    std::cout << "destruct:"<<++n_dstr << '\n';
  }


  int *d;
  static int n_cstr;
  static int n_cptr;
  static int n_dstr;
};
  HasPtrMem getPtrMem()
  {
    return HasPtrMem();
  }

int HasPtrMem::n_cstr=0;
int HasPtrMem::n_cptr=0;
int HasPtrMem::n_dstr=0;

int main(int argc, char const *argv[]) {
  HasPtrMem a = getPtrMem();
  return 0;
}


/**
compaile:
  g++ 3-3-3.cpp --std=c++11 -fno-elide-constructors
res:
  construct: 1
  copystrut:1
  destruct:1
  copystrut:2
  destruct:2
  destruct:3
*/
