#include <iostream>
#include <pthread.h>
#include <mutex>

using namespace std;

recursive_mutex m;

void unsafe_fun() {
    cout << "start unsafe method" << endl;
}

void safe_fun() {
    m.lock();
    cout << "start safe method" << endl;
    m.unlock();
}

void *function1(void *data) {
    m.lock();
    unsafe_fun();
    cout << "thread1" << endl;
    m.unlock();
}

void *function2(void *data) {
    m.lock();
    safe_fun();
    cout << "thread2" << endl;
    m.unlock();
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, &function1, NULL);
    pthread_create(&t1, NULL, &function2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}