#include <stdio.h>
#include <dirent.h>
#include <string.h>

void list_directory_contents(const char *directory_name) {
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

int main(int argc, char *argv[]) {
    if (argc == 1) {
        list_directory_contents(".");
    } else {
        for (int i = 1; i < argc; i++) {
            list_directory_contents(argv[i]);
        }
    }

    return 0;
}