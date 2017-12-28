#include <iostream>
#include <string>

using namespace std;

class complex
{
private:
  double re,im;

public:
  complex():re(0.0),im(0.0){}
  complex(complex& com):re(com.re),im(com.im){cout<<"copy complex constructor"<<endl;}
  // both copy and assign constructor defined. assign one was called first;
  complex(double r):re(r),im(0){cout<<"copy structor"<<endl;}
  complex operator=(double r)
  {
    this->re = r;
    this->im=0;
    cout<<"assign structor"<<endl;
    return *this;
  }
  void display()
  {
    cout << this->re<<", "<<this->im<<endl;
  }
  complex& operator+=(complex a)
  {
    re += a.re;
    im += a.im;
    return *this;
  }

  complex& operator+=(double a)
  {
    re += a;
    return *this;
  }


};

complex operator+(complex a, complex b)
{
  complex tmp = a;
  tmp+=b;
  return tmp;
}

complex operator+(complex a, double b)
{
  return a+=b;
}

complex operator+(double b, complex a)
{
  return a+=b;
}


void foo(complex x, complex y)
{
  y = x + 2;
  y.display();
  y = x+3.0;
  y.display();

  y = y + x;
  y.display();

  y = 2 + x;
  y.display();

  y = 8;
  y.display();
}

int main(int argc, char const *argv[]) {
  complex a,b;
  foo(a,b);
  return 0;
}
