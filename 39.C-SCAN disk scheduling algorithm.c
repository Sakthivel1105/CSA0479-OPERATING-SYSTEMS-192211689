#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to implement C-SCAN algorithm
void c_scan(int arr[], int size, int head) {
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

    // Move to left end if head is the leftmost element
    if (head == 0) {
        seek_count += abs(arr[0] - arr[size - 1]);
    }

    // Calculate the total seek count for the remaining requests
    else {
        int right_seek_count = 0;
        for (int i = 0; i < size; i++) {
            if (abs(arr[i]) >= abs(head)) {
                right_seek_count += abs(arr[i] - head);
            }
        }

        int left_seek_count = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (abs(arr[i]) <= abs(head)) {
                left_seek_count += abs(arr[i] - head);
            }
        }

        seek_count += (right_seek_count < left_seek_count) ? right_seek_count : left_seek_count;
    }

    printf("Total Seek Count for C-SCAN algorithm is %d\n", seek_count);
}

int main() {
    int arr[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int size = sizeof(arr) / sizeof(arr[0]);
    int head = 50;

    c_scan(arr, size, head);

    return 0;
}