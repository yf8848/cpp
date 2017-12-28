#include <thread>
#include <atomic>
#include <cassert>
#include <string>


std::atomic<std::string*> ptr;
int data;

/* thread 1 */
void producer()
{
    std::string* p =new std::string("Hello");   // A
    data = 42; //B
    ptr.store(p, std::memory_order_release); //C
}

/* thread 2 */
void consumer()
{
    std::string* p2=NULL;
    while(!(p2 = ptr.load(std::memory_order_acquire)))  //D
    ;
    assert(*p2 == "Hello");
    assert(data == 42);
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

}