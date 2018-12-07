#include <iostream>
#include <string>

int
main(void){

    std::string str1{"20180301"};
    std::string str2{"20180302"};
    std::string strnow{"20180302"};
    char yesEnd[9]={0};
    snprintf(yesEnd,sizeof(yesEnd),"20180301");

    std::cout<<"compre to str1: "<<strnow.compare(str1)<<std::endl;

    std::cout<<"compre to str2: "<<strnow.compare(str2)<<std::endl;

    std::cout << "compare to yesEnd: "<<strnow.compare(yesEnd) << '\n';

    std::cout << "compare to yesEnd: "<<str1.compare(yesEnd) << '\n';

    exit(0);
}
