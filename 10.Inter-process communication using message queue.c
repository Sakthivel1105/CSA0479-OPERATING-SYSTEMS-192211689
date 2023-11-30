#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

typedef struct {
    long mtype;
    char mtext[20];
} Message;

int main() {
    key_t key;
    int msgid;

    // Generate a unique key for the message queue
    key = ftok("message_queue", 65);
    if (key == -1) {
        perror("Failed to generate key");
        exit(1);
    }

    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Failed to create message queue");
        exit(1);
    }

    // Send a message to the message queue
    Message message;
    message.mtype = 1;
    strcpy(message.mtext, "Hello, World!");

    if (msgsnd(msgid, &message, sizeof(message.mtext), 0) == -1) {
        perror("Failed to send message");
        exit(1);
    }

    // Receive a message from the message queue
    Message received_message;
    if (msgrcv(msgid, &received_message, sizeof(received_message.mtext), 1, 0) == -1) {
        perror("Failed to receive message");
        exit(1);
    }

    printf("Received message: %s\n", received_message.mtext);

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, 0) == -1) {
        perror("Failed to remove message queue");
        exit(1);
    }

    return 0;
}