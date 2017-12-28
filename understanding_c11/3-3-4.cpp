#include <iostream>
using namespace std;

class HasPtrMem{
public:
  HasPtrMem():d(new int(3))
  {
    std::cout << "construct: " <<++n_cstr<< '\n';
  }

  HasPtrMem(const HasPtrMem& h):d(new int(*h.d))
  {
    std::cout << "copy construt:" <<++n_cptr<< '\n';
  }

  HasPtrMem(HasPtrMem&& h):d(h.d)
  {
    //移动构造函数
    h.d=nullptr;  //将临时值的指针置为空;否则临时对象析构会将堆内存释放；导致转移构造函数之后的内存无效
    std::cout << "Move construt :" <<++n_mstr<< '\n';
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
  static int n_mstr;
};
  HasPtrMem getPtrMem()
  {
    HasPtrMem h;
    std::cout << "Resouce from "<<__func__ <<":"<<hex<<h.d<< '\n';
    return h;
  }

int HasPtrMem::n_cstr=0;
int HasPtrMem::n_cptr=0;
int HasPtrMem::n_dstr=0;
int HasPtrMem::n_mstr=0;

int main(int argc, char const *argv[]) {
  HasPtrMem a = getPtrMem();

  std::cout << "Resouce from "<< __func__<<": "<<hex<<a.d << '\n';
  return 0;
}


/**
compaile:
  g++ 3-3-4.cpp --std=c++11 -fno-elide-constructors
res:
  construct: 1
  Resouce from getPtrMem:0x55dd6d656e70
  Move cons :1
  destruct:1
  Move cons :2
  destruct:2
  Resouce from main: 0x55dd6d656e70
  destruct:3

*/
