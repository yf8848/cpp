#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool com_str(const string& a, const string& b)
{
    return a<b;
}

void doump(const vector<string>& v)
{
    for(size_t i = 0; i<v.size();++i)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
    vector<string> v;
    v.push_back("youarenice.");
    v.push_back("youareok");
    v.push_back("youarenice");
    v.push_back("zero.");

    doump(v);
    sort(v.begin(),v.end(),com_str);
    doump(v);
    return 0;
} 