#include <stdio.h>

#define MAX_PROCESSES 10

// Function to implement Rate-Monotonic Scheduling
void rateMonotonic(int at[], int bt[], int dl[], int n) {
    int completionTimes[MAX_PROCESSES] = {0};
    int tat[MAX_PROCESSES] = {0};
    int wt[MAX_PROCESSES] = {0};
    int time = 0;
    int i, j;

    // Sort processes based on burst time (priority)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst time
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap arrival time
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap deadline
                temp = dl[j];
                dl[j] = dl[j + 1];
                dl[j + 1] = temp;
            }
        }
    }

    // Execute processes in priority order (RM)
    for (i = 0; i < n; i++) {
        time += bt[i];
        completionTimes[i] = time;
    }

    // Calculate turnaround and waiting times
    for (i = 0; i < n; i++) {
        tat[i] = completionTimes[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output the execution order
    printf("\nRate-Monotonic Scheduling Order:\n");
    for (i = 0; i < n; i++) {
        printf("P%d ", i);
    }
    printf("\n");

    // Output turnaround and waiting times
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", i, tat[i], wt[i]);
    }
}

// Function to implement Earliest-Deadline First Scheduling
void earliestDeadlineFirst(int at[], int bt[], int dl[], int n) {
    int completionTimes[MAX_PROCESSES] = {0};
    int tat[MAX_PROCESSES] = {0};
    int wt[MAX_PROCESSES] = {0};
    int time = 0;
    int i, j;

    // Sort processes based on deadline (priority)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (dl[j] > dl[j + 1]) {
                // Swap burst time
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap arrival time
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap deadline
                temp = dl[j];
                dl[j] = dl[j + 1];
                dl[j + 1] = temp;
            }
        }
    }

    // Execute processes in priority order (EDF)
    for (i = 0; i < n; i++) {
        time += bt[i];
        completionTimes[i] = time;
    }

    // Calculate turnaround and waiting times
    for (i = 0; i < n; i++) {
        tat[i] = completionTimes[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output the execution order
    printf("\nEarliest-Deadline First Scheduling Order:\n");
    for (i = 0; i < n; i++) {
        printf("P%d ", i);
    }
    printf("\n");

    // Output turnaround and waiting times
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", i, tat[i], wt[i]);
    }
}

// Function to implement Proportional Scheduling
void proportionalScheduling(int at[], int bt[], int dl[], int n) {
    int completionTimes[MAX_PROCESSES] = {0};
    int tat[MAX_PROCESSES] = {0};
    int wt[MAX_PROCESSES] = {0};
    int time = 0;
    int totalBurstTime = 0;
    int i;

    // Calculate total burst time
    for (i = 0; i < n; i++) {
        totalBurstTime += bt[i];
    }

    // Execute processes proportionally based on burst time
    for (i = 0; i < n; i++) {
        int quantum = (bt[i] * 100) / totalBurstTime;
        time += quantum;
        completionTimes[i] = time;
    }

    // Calculate turnaround and waiting times
    for (i = 0; i < n; i++) {
        tat[i] = completionTimes[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output the execution order
    printf("\nProportional Scheduling Order:\n");
    for (i = 0; i < n; i++) {
        printf("P%d ", i);
    }
    printf("\n");

    // Output turnaround and waiting times
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", i, tat[i], wt[i]);
    }
}

int main() {
    int at[MAX_PROCESSES];
    int bt[MAX_PROCESSES];
    int dl[MAX_PROCESSES];
    int n, i;

    printf("Enter the number of processes (max 10): ");
    scanf("%d", &n);

    printf("\nEnter the arrival time, burst time, and deadline for each process:\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess P%d:\n", i);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Deadline: ");
        scanf("%d", &dl[i]);
    }

    // Perform Rate-Monotonic Scheduling
    rateMonotonic(at, bt, dl, n);

    // Perform Earliest-Deadline First Scheduling
    earliestDeadlineFirst(at, bt, dl, n);

    // Perform Proportional Scheduling
    proportionalScheduling(at, bt, dl, n);

    return 0;
}
