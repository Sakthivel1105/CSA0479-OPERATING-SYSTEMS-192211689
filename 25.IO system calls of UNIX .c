#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void create_file(const char *file_name) {
    int fd = open(file_name, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error in open");
        exit(EXIT_FAILURE);
    }
    close(fd);
}

void write_file(const char *file_name, const char *content) {
    int fd = open(file_name, O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error in open");
        exit(EXIT_FAILURE);
    }
    write(fd, content, strlen(content));
    close(fd);
}

void read_file(const char *file_name) {
    int fd = open(file_name, O_RDONLY, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error in open");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    close(fd);
}

void delete_file(const char *file_name) {
    if (unlink(file_name) == -1) {
        perror("Error in unlink");
        exit(EXIT_FAILURE);
    }
}

void print_directory_contents(const char *directory_name) {
    DIR *dir = opendir(directory_name);
    if (dir == NULL) {
        perror("Error in opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

int main() {
    create_file("testfile.txt");
    write_file("testfile.txt", "Hello, World!");
    read_file("testfile.txt");
    delete_file("testfile.txt");

    print_directory_contents(".");

    return 0;
}