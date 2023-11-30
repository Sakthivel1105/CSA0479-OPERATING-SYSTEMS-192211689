#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// P processes shared this array
int turn[10];
int flag[10];

// critical section
void* critical_section(void* arg) {
    int i = *((int*)arg);

    // flag[i] = 1; // trying to enter the critical section
    printf("Process %d trying to enter critical section.\n", i);

    while(flag[i] != 0) {
        // Wait for your turn
        printf("Process %d is waiting.\n", i);
        sleep(1);
    }

    printf("Process %d is in the critical section.\n", i);
    sleep(1); // duration of execution
    printf("Process %d has left the critical section.\n", i);

    flag[i] = 1; // setting the flag[i] = 1, indicating the i-th process has finished

    return NULL;
}

int main(int argc, char* argv[]) {
    int N = 5; // Number of processes
    pthread_t process[N];

    for(int i = 0; i < N; i++) {
        turn[i] = 0;
        flag[i] = 0;
    }

    // create N threads
    for(int i = 0; i < N; i++) {
        pthread_create(&process[i], NULL, critical_section, (void*)&i);
    }

    // join all threads
    for(int i = 0; i < N; i++) {
        pthread_join(process[i], NULL);
    }

    return 0;
}