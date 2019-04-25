#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <conio.h>

void fa();
void fb();
void fc();

pthread_t t1, t2;

void *f1();
void *f2();
sem_t sem;
void main() {
	int n = sem_init(&sem,0,1);
	pthread_create (&t1, NULL, f1, NULL);
	pthread_create (&t2, NULL, f2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}

void *f1() {
	printf("Thread 1 is created\n");
	sleep(1);
	printf("Calling fb()\n");
    fb();
}

void *f2() {
	printf("Thread 2 is created\n\n");

	printf("Calling fa()\n");
	fa();
	sleep(2);

	printf("Calling fc()\n");
	fc();
}

void fa() {
	printf("fa() executed\n\n");
}

void fb() {
	printf("fb() executed\n\n");
}

void fc() {
	printf("fc() executed\n\n");
}



/*  


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <conio.h>

void fa();
void fb();
void fc();

pthread_t t1, t2;

void *f1();
void *f2();
sem_t sem;
void main() {
	int n = sem_init(&sem,1,1);
    //printf("%d", n);
	pthread_create (&t1, NULL, f1, NULL);
    pthread_join(t1, NULL);
    
}

void *f1() {
	printf("Thread 1 is created\n");
    pthread_create (&t2, NULL, f2, NULL);
    pthread_join(t2, NULL);
    
    P();
    //printf("%d", sem);
	printf("Calling fc()\n");
    fb();
    V();
    //printf("%d\n", sem);
}

void *f2() {
	printf("Thread 2 is created\n");
	
	P();
	//printf("%d", sem);
	printf("Calling fa()\n");
	fa();
	V();
	//printf("%d\n", sem);
	
	P();
	//printf("%d", sem);
	printf("Calling fb()\n");
	fc();
	V();
	//printf("%d\n", sem);
}

void fa() {
	printf("fa() executed\n\n");
}

void fb() {
	printf("fc() executed\n\n");
}

void fc() {
	printf("fb() executed\n\n");
}

P () {
	sem = sem-1;
    if (sem <= 0) {
    	while(sem<=0);
    }
}

V() 
{ 
    sem = sem+1; 
    if (sem <= 0) { 
        
    } 
}*/
