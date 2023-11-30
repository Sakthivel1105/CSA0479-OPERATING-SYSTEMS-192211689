#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5
#define MAX_BALANCE 1000

typedef struct {
    int id;
    int balance;
    pthread_mutex_t lock;
} Account;

void *withdraw(void *arg) {
    Account *account = (Account *)arg;
    pthread_mutex_lock(&account->lock);
    if (account->balance >= MAX_BALANCE) {
        account->balance -= MAX_BALANCE;
        printf("Thread %d: Account %d balance after withdrawal: %d\n", pthread_self(), account->id, account->balance);
    } else {
        printf("Thread %d: Account %d balance is too low to withdraw.\n", pthread_self(), account->id);
    }
    pthread_mutex_unlock(&account->lock);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    Account accounts[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        accounts[i].id = i + 1;
        accounts[i].balance = 10000;
        pthread_mutex_init(&accounts[i].lock, NULL);
        pthread_create(&threads[i], NULL, withdraw, (void *)&accounts[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}