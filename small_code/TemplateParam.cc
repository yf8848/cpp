#include <vector>
#include <iostream>
#include <string>

using namespace std;
template<typename T>
void printVec(const vector<T> v)
{
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v[i]<< ' ';
  }
  std::cout << endl;
}

int main(int argc, char const *argv[]) {
  vector<int> v = {1,2,4,65,6};
  vector<double> vd = {1.6,4.7, 8.0};

  printVec(v);
  printVec(vd);

  return 0;
}
