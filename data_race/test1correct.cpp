#include <iostream>
#include <pthread.h>
using namespace std;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

int shared_variable;

void *accumulate_sum(void *data) {
    pthread_mutex_lock(&m);
    shared_variable++;
    pthread_mutex_unlock(&m);
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, &accumulate_sum, NULL);
    pthread_create(&t2, NULL, &accumulate_sum, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}