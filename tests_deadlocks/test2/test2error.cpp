#include <iostream>
#include <pthread.h>
#include <mutex>

using namespace std;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void safe_fun() {
    pthread_mutex_lock(&m);
    cout << "start safe method" << endl;
    pthread_mutex_unlock(&m);
}

void *fun(void *data) {
    pthread_mutex_lock(&m);
    safe_fun();
    cout << "thread1" << endl;
    pthread_mutex_unlock(&m);
}

int main() {
    pthread_t t;

    pthread_create(&t, NULL, &fun, NULL);

    pthread_join(t, NULL);
    return 0;
}