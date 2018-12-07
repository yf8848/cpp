#include <iostream>
#include <string>
#include <regex>

template < typename T, size_t N>    //T 是类型参数，N是非参数类型
void regex1(const T (&fnames)[N])
{
    std::regex txt_reg("[a-z]+\\.txt");
    // 在c++中，`\`会被作为字符串内的转义符，为使`\.`作为正则表达式传递进去生效，
    // 需要对`\`做二次转义，进而有`\\.`。
    for(const auto& fname: fnames){
        std::cout<<fname<<": "<<std::regex_match(fname, txt_reg)<<std::endl;
    }
}

template < typename T, size_t N>
void regex2 (const T (&fnames)[N]) {
    /* code */
    std::regex base_reg("([a-z]+)\\.txt");
    std::smatch base_match;

    for(const auto& fname: fnames){
        if(std::regex_match(fname,base_match,base_reg)){
            // sub_match 的第一个元素匹配整个字符串
            // sug_match 的第二个元素匹配了第一个括号表达式
            if(base_match.size() ==2)
            {
                std::string base=base_match[1].str();
                std::cout<<"sub_match[0]: "<<base_match[0].str()<<std::endl;
                std::cout<<fname<<" sub_match[1]: "<<base<<std::endl;
            }
        }
    }
}

int
main(void){

    std::string fnames[] =
        {"foo.txt","bar.txt","test","a0.txt","AAA.txt","aatxt"};

    regex1(fnames);
    regex2(fnames);
    exit(0);
}


//build: $ g++ regex_test.cpp -std=c++11
/*
$ ./a.exe
foo.txt: 1
bar.txt: 1
test: 0
a0.txt: 0
AAA.txt: 0
aatxt: 0
sub_match[0]: foo.txt
foo.txt sub_match[1]: foo
sub_match[0]: bar.txt
bar.txt sub_match[1]: bar
*/
