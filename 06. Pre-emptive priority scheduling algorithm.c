#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
};

int main() {
    int n, total_waiting_time = 0;
    float average_waiting_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter process ID, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d", &p[i].pid, &p[i].burst_time, &p[i].priority);
    }

    int t = 0;
    while (t < n) {
        int i, max = -1;
        for (i = 0; i < n; i++) {
            if (p[i].burst_time > 0 && p[i].priority > max) {
                max = p[i].priority;
                t = i;
            }
        }

        if (p[t].burst_time <= 0) {
            continue;
        }

        total_waiting_time += t;
        p[t].waiting_time = total_waiting_time - p[t].burst_time;
        p[t].burst_time--;
    }

    printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time + 1, p[i].priority, p[i].waiting_time);
    }

    average_waiting_time = (float) total_waiting_time / n;
    printf("\nAverage waiting time = %.2f\n", average_waiting_time);

    return 0;
}