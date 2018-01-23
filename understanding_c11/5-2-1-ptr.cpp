#include <memory>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  unique_ptr<int> up1(new int(11));
  // 无法复制unique_ptr
  //unique_ptr<int> up2=up1;

  cout<<*up1<<endl; //11
  unique_ptr<int> up3 = move(up1);  //up3是数据的唯一unique_ptr
  cout<<*up3<<endl;
//std::cout << *up1 << '\n';  //运行时错误
  up3.reset();  //显示释放内存
  up1.reset();  //不会导致运行时错误
  //std::cout << *up3 << '\n';  //运行时错误

  shared_ptr<int> sp1(new int(22));
  shared_ptr<int> sp2=sp1;

  std::cout << *sp1 << '\n';
  std::cout << *sp2 << '\n';
  sp1.reset();
  std::cout << *sp2 << '\n';

  return 0;
}
