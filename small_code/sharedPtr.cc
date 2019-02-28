#include <iostream>
#include<memory>

using namespace std;

int main(int argc, char const *argv[])
{
    std::shared_ptr<int> sptr = std::make_shared<int>(2);

    cout<<*sptr<<":"<<sptr.use_count()<<endl;

    shared_ptr<int> sptr2 (sptr);
    
    int b =20;
    shared_ptr<int> ptrb = make_shared<int>(b);

    cout<< sptr.use_count()<<","<<sptr2.use_count()<<","<<ptrb.use_count()<<endl;


    sptr2 = ptrb;
    cout<< sptr.use_count()<<","<<sptr2.use_count()<<","<<ptrb.use_count()<<endl;

    return 0;
}
