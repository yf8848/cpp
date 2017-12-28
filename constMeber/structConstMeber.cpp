#include <iostream>
#include <string>

using namespace std;

struct X
{
  const int a;
  const int& r;

  // const and refer member in struct（or）class must be initilized in destructor manually
  X(int a =10):a(a),r(a)
  {}
};

int main(int argc, const char *argv[]) {
  X x;
  cout<<x.a<<", "<<x.r<<endl;
  return 0;
}
