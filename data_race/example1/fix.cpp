#include <stdlib.h>
#include <thread>
#include <mutex>

struct BitFields {
    int a:4, b:4;
};

BitFields x;
std::mutex mtx;

void Thread1() {
	mtx.lock();
    x.a++;
    mtx.unlock();
}

void Thread2() {
	mtx.lock();
    x.b++;
    mtx.unlock();
}

int main() {
    std::thread t1(Thread1);
    std::thread t2(Thread2);

    t1.join();
    t2.join();

    return 0;
}
