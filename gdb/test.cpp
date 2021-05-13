#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
using namespace std;

int threadIndex = 1;

void threadFuncA(int index)
{
    cout << "this is thread index " << index << " threadIndex is " 
    << threadIndex << endl;
    this_thread::sleep_for(chrono::microseconds(index));
    threadIndex = index;
}

void threadFuncB(int index)
{
    // 加锁
    static mutex mtx;
    lock_guard<mutex> lock(mtx);

    cout << "this is thread index " << index << " threadIndex is " 
    << threadIndex << endl;
    this_thread::sleep_for(chrono::microseconds(index));
    threadIndex = index;
}

void threadFuncC(int index)
{
    // 加锁
    static mutex mtx;
    unique_lock<mutex> lock(mtx);

    cout << "this is thread index " << index << " threadIndex is " 
    << threadIndex << endl;

    lock.unlock();

    this_thread::sleep_for(chrono::microseconds(index));

    lock.lock();
    threadIndex = index;
}

int main()
{
    cout << "hello world" << endl;
    // 创建线程池
    vector<thread> threadPool;
    for (int i = 1; i < 5; i++) {
        threadPool.push_back(thread (threadFuncC, i));
    }
    // 启动线程
    for (auto th = threadPool.begin(); th != threadPool.end(); th++) {
        th->join();
    }

    cout << "the final index is " << threadIndex << endl;
    /*
    while (true) {
        int a = 10;
        int b = a;
    }
    */
    return 0;
}