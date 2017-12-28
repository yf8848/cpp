#include <iostream>

using namespace std;

class HasPtrMem{
public:
  HasPtrMem():d(new int(0)){}
  HasPtrMem(const HasPtrMem& h):d(new int(*h.d)){}  //拷贝构造函数，从堆中非配内存，由*h.d初始化

  ~HasPtrMem(){delete d; }

  int* d;
};

int main(int argc, char const *argv[]) {
  HasPtrMem a;
  HasPtrMem b(a);
  cout<<*a.d<<endl;
  cout<<*b.d<<endl;
  return 0;
}

/**
  使用a初始化变量b,这回调用拷贝构造函数，这里的拷贝构造函数有编译器隐式生成，
  其作用类似于memcpy的按位拷贝，这样的构造方式有一个问题，a.d和b.d指向同一块堆内存，
  因此在main的作用域结束的时候，a,b的析构函数纷纷被调用，当其中之一完成析构，
  另一个就成了悬挂指针，不再指向有效内存；

  修正方案看下一段代码；
*/
