#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int burst_time;
    int waiting_time;
};

int find_min_burst_time(struct process p[], int n) {
    int min = 99999, index = -1;
    for (int i = 0; i < n; i++) {
        if (p[i].burst_time < min) {
            min = p[i].burst_time;
            index = i;
        }
    }
    return index;
}

int main() {
    int n, total_waiting_time = 0;
    float average_waiting_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter process ID and burst time for process %d: ", i + 1);
        scanf("%d %d", &p[i].pid, &p[i].burst_time);
    }

    int t = 0;
    while (t < n) {
        int index = find_min_burst_time(p, n);
        total_waiting_time += t;
        p[index].waiting_time = total_waiting_time - p[index].burst_time;
        p[index].burst_time = 0;
        t++;
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].waiting_time);
    }

    average_waiting_time = (float) total_waiting_time / n;
    printf("\nAverage waiting time = %.2f\n", average_waiting_time);

    return 0;
}