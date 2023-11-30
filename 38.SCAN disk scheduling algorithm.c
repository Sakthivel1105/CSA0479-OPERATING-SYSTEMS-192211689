#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to implement SCAN algorithm
void scan(int arr[], int size, int head) {
    // Calculate total seek count
    int seek_count = 0;

    // Sort the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (abs(arr[j]) > abs(arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Find number of elements less than head
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (abs(arr[i]) < abs(head))
            count++;
    }

    // Move to right end if head is the rightmost element
    if (count == 0) {
        int left = abs(head - arr[0]);
        int right = abs((head + 1) - arr[0]);
        seek_count += (left < right) ? left : right;
    }

    // Find the minimum seek count for each direction
    else {
        int min_seek_count = abs(arr[count] - head);
        int left_count = count, right_count = size - count - 1;

        if (left_count < right_count) {
            seek_count += min_seek_count;
        } else {
            seek_count += (2 * min_seek_count) - left_count;
        }
    }

    printf("Total Seek Count for SCAN algorithm is %d\n", seek_count);
}

int main() {
    int arr[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int size = sizeof(arr) / sizeof(arr[0]);
    int head = 50;

    scan(arr, size, head);

    return 0;
}