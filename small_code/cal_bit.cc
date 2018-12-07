#include <iostream>

int main(int argc, char const *argv[]) {
    int i=65535,j=0x000a,k;
    std::cout<<(k=i&j)<<std::endl;

    int x,y,z;
    x=y=(z=8,4*6);
    std::cout<<x<<","<<y<<std::endl;

    std::cout<<'\17'<<"|"<<'\771' <<"|"<<
'\01711'<<"|"<<
'\092'<<std::endl;


int e=8;
double f=6.4,g=8.9;
std::cout<< (f+int(e/3*int(f+g)/2)%4) <<std::endl;
    return 0;
}
