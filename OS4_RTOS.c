#include <stdio.h>

#define MAX_PROCESSES 10
int at[MAX_PROCESSES], bt[MAX_PROCESSES], dl[MAX_PROCESSES], p[MAX_PROCESSES], n, i;
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void rateMonotonic() {
	int j;
	    for (i = 0; i < n - 1; i++) {
    	for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) { // Sort based on arrival time
                swap(&bt[j], &bt[j + 1]);
                swap(&at[j], &at[j + 1]);
                swap(&dl[j], &dl[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
    	}
    }
	for (i = 0; i < n - 1; i++) {
    	for (j = 0; j < n - i - 1; j++) {
        	if (bt[j] > bt[j + 1] && at[j]<=at[j+1]) {
            	swap(&bt[j], &bt[j+1]);
   	            swap(&at[j], &at[j+1]);
            	swap(&dl[j], &dl[j+1]);
            	swap(&p[j], &p[j+1]);
        	}
    	}
	}
	printf("\nRate-Monotonic Scheduling Order:\n");
	for (i = 0; i < n; i++) {
    	printf("P%d ", p[i]);
	}
	printf("\n");
}

void earliestDeadlineFirst() {
	int j;

    for (i = 0; i < n - 1; i++) {
    	for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) { // Sort based on arrival time
                swap(&bt[j], &bt[j + 1]);
                swap(&at[j], &at[j + 1]);
                swap(&dl[j], &dl[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
    	}
    }
	for (i = 0; i < n - 1; i++) {
    	for (j = 0; j < n - i - 1; j++) {
        	if (dl[j] > dl[j + 1] && at[j]<=at[j+1]) {
            	swap(&bt[j], &bt[j+1]);
   	            swap(&at[j], &at[j+1]);
   	            swap(&dl[j], &dl[j+1]);
            	swap(&p[j], &p[j+1]);
        	}
    	}
	}
	printf("\nEarliest-Deadline First Scheduling Order:\n");
	for (i = 0; i < n; i++) {
    	printf("P%d ", p[i]);
	}
	printf("\n");
}

void proportionalScheduling() {
	int totalBurstTime = 0;
	int i; 
	float share[10];

	for (i = 0; i < n; i++) {
    	totalBurstTime += bt[i];
	}

	for (i = 0; i < n; i++) {
    	share[i] = (bt[i] * 100) / totalBurstTime;
	}
	printf("\nProportional Scheduling Order:\n");
	for (i = 0; i < n; i++) {
        	printf("P%d gets %.2f%% CPU\n", i, share[i]);
   	}
	printf("\n");
}

int main() {
	printf("Enter the number of processes: ");
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
    	p[i]=i;
	}
	rateMonotonic();
	earliestDeadlineFirst();
	proportionalScheduling();

	return 0;
}
