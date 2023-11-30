#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[50];

    // Creating a new file using the O_CREAT flag
    fd = open("testfile.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error in open");
        exit(EXIT_FAILURE);
    }

    // Writing data to the file
    write(fd, "Hello, World!", 13);

    // Closing the file
    close(fd);

    // Reopening the file using the O_APPEND flag
    fd = open("testfile.txt", O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error in open");
        exit(EXIT_FAILURE);
    }

    // Writing additional data to the file
    write(fd, " This is an appended message.", 24);

    // Closing the file
    close(fd);

    // Opening the file for reading
    fd = open("testfile.txt", O_RDONLY, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error in open");
        exit(EXIT_FAILURE);
    }

    // Reading data from the file
    read(fd, buffer, 50);

    // Closing the file
    close(fd);

    // Printing the contents of the file
    printf("File contents: %s\n", buffer);

    // Deleting the file using the unlink system call
    unlink("testfile.txt");

    return 0;
}