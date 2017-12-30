#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Screen
{
public:
  using pos = std::string::size_type;
  Screen()=default;

  Screen(pos ht, pos wd, char c):
    height(ht),with(wd),contents(wd*ht, c)
  {}

  char get() const
  {
    return contents[cursor];
  }

  inline char get(pos ht, pos wd) const
  {
    return contents[ht*with+wd];
  }

  Screen& move(pos r, pos c);

  Screen& set(char);

  Screen& set(pos, pos, char);

  Screen& display(std::ostream& os)
  {
    do_display(os);
    return *this;
  }

  const Screen& display(std::ostream& os) const
  {
    os<<"const display access num: "<<++con_acc_num<<" ";
    do_display(os);
    return *this;
  }

private:
  pos cursor=0;
  pos height=0,with=0;
  std::string contents;
  mutable size_t access_num=0,con_acc_num=0;

private:
  void do_display(std::ostream& os) const
  {
    os<<"access num:["<<++access_num<<"] "<<contents<<endl;
  }
};

inline
Screen& Screen::move(pos r, pos c)
{
  cursor = r*with+c;
  return *this;
}

inline
Screen& Screen::set(char c)
{
  contents[cursor]=c;
  return *this;
}

inline
Screen& Screen::set(pos r, pos col, char c)
{
  contents[r*with+col]=c;
  return *this;
}


int main(int argc, char const *argv[]) {
  Screen myScreen(5,5,'a');
  const Screen conScreen(5,5,'b');
  myScreen.display(cout);
  myScreen.set('A').move(1,1).set('B').display(cout);
  /* 非常量引用调用非常量版本display函数，返回指向非常亮引用的this */
  myScreen.display(cout).move(2,2).set('C').display(cout);

  /*常量实例调用常量版本display函数，返回常量引用，且不可调用move，set函数*/
  conScreen.display(cout).display(cout);
  return 0;
}
