#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

string testStr(const string& strTime){
    // 取年、月、日
    int year=0, month=0, day=0, hour=0, minute=0, second=0;
    char strf[20];
    sscanf(strTime.c_str(), "%04d%02d%02d%02d%02d%02d", &year, &month, &day, &hour, &minute, &second);
    sprintf(strf,"%04d-%02d-%02d %02d:%02d:%02d",year,month,day,hour,minute,second);
    return strf;
}

int main()
{
    string strTime = "20180316100001";
    cout<<testStr(strTime)<<endl;

    string strTime1 = "20180316";
    cout<<testStr(strTime1)<<endl;

    string strTime2 = "201803161502";
    cout<<testStr(strTime2)<<endl;

    return 0;
}