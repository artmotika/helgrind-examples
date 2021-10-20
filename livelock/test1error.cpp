#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;


pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

void *function1(void *data) {
    while(true) {
        sleep(1);
        pthread_mutex_lock(&m1);
        printf("lock1 acquired, trying to acquire lock2.\n");

        if (!pthread_mutex_trylock(&m2)) {
            printf("lock2 acquired.\n");
        } else {
            printf("cannot acquire lock2, releasing lock1.\n");
            pthread_mutex_unlock(&m1);
            continue;
        }

        printf("executing first operation.\n");
        break;
    }
    pthread_mutex_unlock(&m2);
    pthread_mutex_unlock(&m1);
}

void *function2(void *data) {
    while (true) {
        pthread_mutex_lock(&m2);
        printf("lock2 acquired, trying to acquire lock1.\n");

        if (!pthread_mutex_trylock(&m1)) {
            printf("lock1 acquired.\n");
        } else {
            printf("cannot acquire lock1, releasing lock2.\n");
            pthread_mutex_unlock(&m2);
            continue;
        }

        printf("executing second operation.\n");
        break;
    }
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