#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

#define COMP(a,b) ((a)<(b))

bool compVec(int a, int b){ return a < b;}

void printVec(vector<int>& vec)
{
    for(int i=0; i<vec.size(); ++i)
        cout<<" "<<vec[i];
    cout<<endl;
}

void fillVec(vector<int>& vec, int n)
{
    for(int i=0;i <n; i++)
    {
        int t = rand();
        vec.push_back(t);
    }
}

int main()
{
    vector<int> vin;
    fillVec(vin, 10);

    printVec(vin);

    sort(vin.begin(), vin.end(), compVec);

    printVec(vin);

    return 0;
}