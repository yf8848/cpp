#include <iostream>
#include "string"

using namespace std;

void Fun(string& str1, string& str2, string str3)
{
  // a temp string vlue when str1+str2+str3, and its c_str() function be called.
  //a temp value returned to cstr.
  // when cout, the temp value was destoryed and cout NULL;
  string tempStr = (str1 + str2 + str3);
  const char* cstr = tempStr.c_str();
  cout << cstr<<endl;

  // or use it at same expression
  cout<<(str1 + str2 + str3).c_str()<<endl;
}

int main(int argc, char const *argv[]) {
  string str1("xiAn "),str2("DianZiKeJI"),str3("DaXue");
  Fun(str1, str2, str3);
  return 0;
}
