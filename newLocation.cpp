#include <iostream>

using namespace std;

class X
{
public:
  X(){}
  X(int){}
  void* operator new(size_t, void* p)
  {
    return p;
  }
};



int main(int argc, char const *argv[]) {
  /* code */

  void* buf = reinterpret_cast<void*>(0xF00F);
  X* p2 = new (buf)X;
  cout<<&p2<<","<<p2<<endl;
  return 0;
}
