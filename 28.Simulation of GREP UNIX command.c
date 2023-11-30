#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fnmatch.h>

void grep_directory_contents(const char *directory_name, const char *pattern) {
    DIR *dir = opendir(directory_name);
    if (dir == NULL) {
        perror("Error in opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (fnmatch(pattern, entry->d_name, 0) == 0) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory> <pattern>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *directory_name = argv[1];
    const char *pattern = argv[2];

    grep_directory_contents(directory_name, pattern);

    return 0;
}