#include <stdio.h>
#define MAX_PROCESSES 100
void roundRobinScheduling(int bt[], int n, int qt) {
    int wt[MAX_PROCESSES] = {0};
    int tat[MAX_PROCESSES] = {0};
    int rt[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    int cp = 0;
    int current_time = 0;

    while (cp < n) {
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] <= qt) {
                    current_time += rt[i];
                    rt[i] = 0;
                    tat[i] = current_time;
                    cp++;
                } else {
                    current_time += qt;
                    rt[i] -= qt;
                }
                wt[i] = current_time - bt[i];
            }
        }
    }

    printf("Process\t| Burst Time\t| Waiting Time\t| Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t| %d\t\t| %d\t\t| %d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}
void priorityNonPreemptiveScheduling(int bt[], int priority[], int n) {
    int wt[MAX_PROCESSES] = {0};
    int tat[MAX_PROCESSES] = {0};
    int ct[MAX_PROCESSES] = {0};
    for (int i = 0; i < n; i++) {
        int min_priority = priority[i];
        int min_priority_index = i;

        for (int j = i + 1; j < n; j++) {
            if (priority[j] < min_priority) {
                min_priority = priority[j];
                min_priority_index = j;
            }
        }
        int temp = bt[i];
        bt[i] = bt[min_priority_index];
        bt[min_priority_index] = temp;

        temp = priority[i];
        priority[i] = priority[min_priority_index];
        priority[min_priority_index] = temp;
    }
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        ct[i] = current_time;
        wt[i] = current_time;
        current_time += bt[i];
        tat[i] = current_time;
    }
    printf("Pno|Bt\t|Wt\t|Tat\n");
    for (int i = 0; i < n; i++) {
        printf("%d  |%d\t|%d\t|%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int choice;
    int n, qt;
    int bt[MAX_PROCESSES];
    int priority[MAX_PROCESSES];
    printf("Menu:\n1. Round Robin Scheduling\n2. Priority Non-preemptive Scheduling\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the number of processes: ");
            scanf("%d", &n);

            printf("Enter the time quantum: ");
            scanf("%d", &qt);

            printf("Enter burst time for each process:\n");
            for (int i = 0; i < n; i++) {
                scanf("%d", &bt[i]);
            }

            roundRobinScheduling(bt, n, qt);
            break;

        case 2:
            printf("Enter the number of processes: ");
            scanf("%d", &n);

            printf("Enter burst time and priority for each process:\n");
            for (int i = 0; i < n; i++) {
                scanf("%d %d", &bt[i], &priority[i]);
            }

            priorityNonPreemptiveScheduling(bt, priority, n);
            break;

        default:
            printf("Invalid choice!\n");
            return 0;
    }
    return 0;
}
