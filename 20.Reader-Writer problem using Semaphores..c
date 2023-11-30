#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_READERS 5
#define NUM_WRITERS 5

sem_t read_mutex;
sem_t write_mutex;
int data = 0;

void *reader(void *arg) {
    sem_wait(&read_mutex);
    printf("Reader %ld is reading data: %d\n", pthread_self(), data);
    sem_post(&read_mutex);
    return NULL;
}

void *writer(void *arg) {
    sem_wait(&write_mutex);
    data++;
    printf("Writer %ld is writing data: %d\n", pthread_self(), data);
    sem_post(&write_mutex);
    return NULL;
}

int main() {
    pthread_t threads[NUM_READERS + NUM_WRITERS];
    sem_init(&read_mutex, 0, 1);
    sem_init(&write_mutex, 0, 1);

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_create(&threads[i], NULL, reader, NULL);
    }

    for (int i = NUM_READERS; i < NUM_READERS + NUM_WRITERS; i++) {
        pthread_create(&threads[i], NULL, writer, NULL);
    }

    for (int i = 0; i < NUM_READERS + NUM_WRITERS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&read_mutex);
    sem_destroy(&write_mutex);

    return 0;
}