#include <iostream>
#include <string>
#include <map>
#include <vector> 

using namespace std;

typedef struct _ACC_ITEM
{
    string Fname;
    int age;
    _ACC_ITEM():Fname("default"),age(0)
    {}
}ACC_ITEM;

const int NUM = 10;
int main()
{
    vector<ACC_ITEM> map_int_item;
    map<string,ACC_ITEM> map_str_item;
    map_int_item.resize(NUM);
    
    for(int i=0; i< NUM; ++i)
    {
        ACC_ITEM& acc = map_int_item[i];
        acc.Fname = to_string(i)+" num to string";
        acc.age = i;

        map_str_item.insert(make_pair(acc.Fname, acc));
    }

    cout << "size before: "<< map_int_item.size()<<","<<map_str_item.size()<<endl;

    for(vector<ACC_ITEM>::iterator it=map_int_item.begin(); it != map_int_item.end(); ++it)
    {
        map_int_item.erase(it);
    } 

    cout << "size before: "<< map_int_item.size()<<","<<map_str_item.size()<<endl;

    return 0;
}