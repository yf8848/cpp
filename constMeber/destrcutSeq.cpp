#include <iostream>

using namespace std;

struct X
{
  int a;
  int b;

  X()
  {
    cout<<"X structor"<<endl;
  }

  ~X()
  {
    cout<<"~X destructor"<<endl;
  }
};

class XX
{
private:
  X x;
  int a;
public:
  XX():x(),a(0)
  {
    cout<<"XX, structor"<<endl;
  }
  ~XX()
  {
    cout<<"~XX, destructor"<<endl;
  }
};
// structor X is before XX;
// but XX's destructor was runned firsr than his member's X
int main(int argc, char const *argv[]) {
  XX x;
  return 0;
}
