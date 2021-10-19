#include <stdlib.h>
#include <thread>

struct BitFields {
    int a:4, b:4;
};

BitFields x;

void Thread1() {
    x.a++;
}

void Thread2() {
    x.b++;
}

int main() {
    std::thread t1(Thread1);
    std::thread t2(Thread2);

    t1.join();
    t2.join();

    return 0;
}
