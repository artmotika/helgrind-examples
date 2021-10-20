#include <iostream>
#include <pthread.h>
using namespace std;

int shared_variable;

void *accumulate_sum(void *data) {
    shared_variable++;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, &accumulate_sum, NULL);
    pthread_create(&t2, NULL, &accumulate_sum, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}