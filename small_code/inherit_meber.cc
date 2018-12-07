#include <iostream>

using namespace std;
class A
{
public:

public:
  int a;
};

class B:public A
{
public:
  void printMemberB(){cout<<"meber in B :"<< a <<endl;}
  void setMeberB(){a = 2;}
};

class C:public B
{
public:
  void printMemberC(){cout<<"meber in C :"<< a <<endl;}
  void setMeberC(){a = 4;}
};

int main()
{
 C c;
 c.setMeberB();
 c.printMemberC();
 c.printMemberB();

 c.setMeberC();
 c.printMemberC();
 c.printMemberB();

 return 0;
}
