#include <iostream>
#include <string>

using namespace std;

int
main(){
    string skey="01234554@344";
    string sac,scur;
    size_t pos=skey.find('@');
    if(pos != std::string::npos)
    {
        sac=skey.substr(0,pos);
        scur=skey.substr(pos+1);
    }else{
        sac="null";
        scur=skey;
    }

    cout<<sac<<"\t"<<scur<<endl;
}