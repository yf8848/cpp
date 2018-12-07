#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main ()
{
    std::string str="We think in generalities, but we live in details";
    string s = str.substr(str.size()-3);
    const string& sref = str;
    cout<<str<<"\t"<<s<<","<<sref.substr(sref.size()-4)<<endl;

    vector<string> v;
    v.push_back(sref);

    cout<<v[v.size()-1]<<endl;
    return 0;
}