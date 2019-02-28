#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

mutex mtx_g;
int g_i =0;
volatile int g_vi =0;

void incrment_local_mutex()
{
    mutex mtx;
    lock_guard<mutex> lm(mtx);
    cout<< this_thread::get_id()<< ": " << ++g_i<<endl;
}

void incrment_local_mutex_vo()
{
    mutex mtx;
    lock_guard<mutex> lm(mtx);
    cout<< this_thread::get_id()<< ": " << ++g_vi<<endl;
}

void incrment_global_mutex()
{
    lock_guard<mutex> lm(mtx_g);
    cout<< this_thread::get_id()<< ": " << ++g_i<<endl;
}

int main(int argc, char const *argv[])
{
    thread ths[100];
    for(int i =0; i< 100; ++i)
    {
        ths[i] = thread(incrment_local_mutex_vo);
    }

    for(auto &th: ths)
    {
        th.join();
    }

    cout<< g_i<<"-"<<g_vi << " incresses finished."<<endl;
    return 0;
}
