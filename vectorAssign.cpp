#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<int> v;
	v.assign(10, 0);

	cout << v.size() << ", "<<v.capacity()<<endl;

	return 0;
}
