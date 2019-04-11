#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t t1, t2;
void *f1();
void *f2();
sem_t semaphore;
void main() {
	sem_init(&semaphore,0,1);
    pthread_create (&t1, NULL, f1, NULL);
    pthread_join(t1, NULL);

}

void *f1() {
	printf("Thread 1 created\n");
    pthread_create (&t2, NULL, f2, NULL);
    pthread_join(t2, NULL);
}

void *f2() {
	printf("Thread 2 created\n");
}
