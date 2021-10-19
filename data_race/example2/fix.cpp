#include <stdlib.h>
#include <thread>
#include <mutex>

int shared_variable;

std::mutex mtx;

void Thread1() {
	mtx.lock();
    shared_variable++;
    mtx.unlock();
}

void Thread2() {
	mtx.lock();
    shared_variable++;
    mtx.unlock();
}

int main() {
    std::thread t1(Thread1);
    std::thread t2(Thread2);

    t1.join();
    t2.join();

    return 0;
}
