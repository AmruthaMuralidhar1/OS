#include <stdio.h>
#include <stdlib.h>
void calculateFCFSAverageTime() {
    int n, i;
    int bt[50], wt[50], tt[50];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    wt[0] = 0; // Waiting time for the first process is 0

    // Calculate waiting time for subsequent processes
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time for each process
    for (i = 0; i < n; i++) {
        tt[i] = bt[i] + wt[i];
    }

    // Display the results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tt[i]);
    }

    // Calculate average waiting time
    float avg_wt = 0;
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
    }
    avg_wt /= n;
    printf("Average Waiting Time: %.2f\n", avg_wt);

    // Calculate average turnaround time
    float avg_tt = 0;
    for (i = 0; i < n; i++) {
        avg_tt += tt[i];
    }
    avg_tt /= n;
    printf("Average Turnaround Time: %.2f\n", avg_tt);
}

void calculateSJFAverageTime() {
    int n, i, j;
    int bt[50], wt[50], tt[50];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Sort the burst time in ascending order using Selection Sort
    for (i = 0; i < n; i++) {
        int minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[minIndex]) {
                minIndex = j;
            }
        }

        // Swap burst times and process IDs
        int temp = bt[minIndex];
        bt[minIndex] = bt[i];
        bt[i] = temp;

        temp = wt[minIndex];
        wt[minIndex] = wt[i];
        wt[i] = temp;
    }

    wt[0] = 0; // Waiting time for the first process is 0

    // Calculate waiting time for subsequent processes
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time for each process
    for (i = 0; i < n; i++) {
        tt[i] = bt[i] + wt[i];
    }

    // Display the results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tt[i]);
    }

    // Calculate average waiting time
    float avg_wt = 0;
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
    }
    avg_wt /= n;
    printf("Average Waiting Time: %.2f\n", avg_wt);

    // Calculate average turnaround time
    float avg_tt = 0;
    for (i = 0; i < n; i++) {
        avg_tt += tt[i];
    }
    avg_tt /= n;
    printf("Average Turnaround Time: %.2f\n", avg_tt);
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Calculate Average Time using FCFS\n");
        printf("2. Calculate Average Time using SJF\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateFCFSAverageTime();
                break;

            case 2:
                calculateSJFAverageTime();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
