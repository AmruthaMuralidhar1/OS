//Menu drived
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int taskID;
    int arrivalTime;
    int burstTime;
    int deadline;
    float priority; } Task;
void rateMonotonic(Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tasks[j].deadline > tasks[j + 1].deadline) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
        printf("\nExecuting Rate-Monotonic scheduling algorithm.\n");
    printf("Task execution order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tasks[i].taskID);
    }
    printf("\n");
}
void earliestDeadlineFirst(Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tasks[j].deadline > tasks[j + 1].deadline) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
    printf("\nExecuting Earliest-Deadline First scheduling algorithm.\n");
    printf("Task execution order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tasks[i].taskID);
    }
    printf("\n");
}
void proportionalScheduling(Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tasks[j].priority < tasks[j + 1].priority) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
    printf("\nExecuting Proportional Scheduling algorithm.\n");
    printf("Task execution order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tasks[i].taskID);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);    
    Task tasks[n];
    for (int i = 0; i < n; i++) {
        printf("\nTask %d:\n", i + 1);
        printf("Enter Task ID: ");
        scanf("%d", &tasks[i].taskID);
        printf("Enter Arrival Time: ");
        scanf("%d", &tasks[i].arrivalTime);
        printf("Enter Burst Time: ");
        scanf("%d", &tasks[i].burstTime);
        printf("Enter Deadline: ");
        scanf("%d", &tasks[i].deadline);
        printf("Enter Priority (for Proportional Scheduling): ");
        scanf("%f", &tasks[i].priority);
    }    
    int choice;    
    do {
        printf("\n----- CPU Scheduling Simulation -----\n");
        printf("1. Rate-Monotonic Scheduling\n");
        printf("2. Earliest-Deadline First Scheduling\n");
        printf("3. Proportional Scheduling\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);        
        switch (choice) {
            case 1:
                rateMonotonic(tasks, n);
                break;
            case 2:
                earliestDeadlineFirst(tasks, n);
                break;
            case 3:
                proportionalScheduling(tasks, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }        
    } while (choice != 4);    
    return 0;
}

