#include <stdlib.h>
#include <thread>

int shared_variable;

void Thread1() {
    shared_variable++;
}

void Thread2() {
    shared_variable++;
}

int main() {
    std::thread t1(Thread1);
    std::thread t2(Thread2);

    t1.join();
    t2.join();

    return 0;
}
