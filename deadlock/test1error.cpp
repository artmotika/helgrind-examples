#include <iostream>
#include <pthread.h>
using namespace std;

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

void *function1(void *data) {
    pthread_mutex_lock(&m2);
    pthread_mutex_lock(&m1);
    cout << "thread1" << endl;
    pthread_mutex_unlock(&m1);
    pthread_mutex_unlock(&m2);
}

void *function2(void *data) {
    pthread_mutex_lock(&m1);
    pthread_mutex_lock(&m2);
    cout << "thread2" << endl;
    pthread_mutex_unlock(&m1);
    pthread_mutex_unlock(&m2);
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, &function1, NULL);
    pthread_create(&t2, NULL, &function2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}