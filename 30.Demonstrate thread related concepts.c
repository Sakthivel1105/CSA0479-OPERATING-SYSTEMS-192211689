// Create a thread
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_message(void* arg) {
    printf("Thread: %s\n", (char*)arg);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    pthread_t thread1, thread2;
    char *message1 = "Hello, World!";
    char *message2 = "This is another thread.";

    // Create threads
    pthread_create(&thread1, NULL, print_message, (void*)message1);
    pthread_create(&thread2, NULL, print_message, (void*)message2);

    // Join threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Threads have been joined.\n");
    return 0;
}