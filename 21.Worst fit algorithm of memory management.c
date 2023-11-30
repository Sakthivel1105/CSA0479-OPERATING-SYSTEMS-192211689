#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 10

void worstFit(int blockSize[], int m, int n) {
    int i, j, max, index, curr_size, curr_index = 0;

    for (i = 0; i < n; i++) {
        max = -1;
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= blockSize[i]) {
                curr_size = blockSize[j] - blockSize[i];
                if (curr_size > max) {
                    max = curr_size;
                    index = j;
                }
            }
        }
        blockSize[index] -= blockSize[i];
        printf("Block %d is assigned to Process %d\n", index, i);
        curr_index++;
    }
}

int main() {
    int blockSize[] = {100, 500, 150, 200};
    int processSize[] = {212, 417, 100, 150, 250};
    int i, j, k, n = sizeof(processSize) / sizeof(processSize[0]), m = sizeof(blockSize) / sizeof(blockSize[0]);

    worstFit(blockSize, m, n);

    return 0;
}