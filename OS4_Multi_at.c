#include<stdio.h>
#include<stdlib.h>

int main() {
    int p[30], bt[30], su[30], wt[30], tat[30], at[30], i, k, n, temp;
    float waiting_avg, turnaround_avg;
    int tr;
    int csource = 0;
    int cuser = 0;
    int btsource[30], btuser[30], puser[30], psource[30], atsource[30], atuser[30];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("System process/User Process (0/1) for Process %d: ", i);
        scanf("%d", &tr);
        printf("Enter the Burst Time of Process %d: ", i);
        if (tr == 1) {
            scanf("%d", &btuser[cuser]);
            printf("Enter the Arrival Time of Process %d: ", i);
            scanf("%d", &atuser[cuser]);
            puser[cuser] = i;
            cuser++;
        } else if (tr == 0) {
            scanf("%d", &btsource[csource]);
            printf("Enter the Arrival Time of Process %d: ", i);
            scanf("%d", &atsource[csource]);
            psource[csource] = i;
            csource++;
        }
    }

    for (i = 0; i < csource; i++) {
        p[i] = psource[i];
        bt[i] = btsource[i];
        at[i] = atsource[i];
        su[i] = 0;
    }

    for (i = 0; i < cuser; i++) {
        p[i + csource] = puser[i];
        bt[i + csource] = btuser[i];
        at[i + csource] = atuser[i];
        su[i + csource] = 1;
    }

    // Sort the processes based on their arrival time using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (k = 0; k < n - i - 1; k++) {
            if (at[k] > at[k + 1]) {
                temp = at[k];
                at[k] = at[k + 1];
                at[k + 1] = temp;

                temp = p[k];
                p[k] = p[k + 1];
                p[k + 1] = temp;

                temp = bt[k];
                bt[k] = bt[k + 1];
                bt[k + 1] = temp;

                temp = su[k];
                su[k] = su[k + 1];
                su[k + 1] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    waiting_avg = wt[0];
    turnaround_avg = tat[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1] - at[i] + at[i - 1];
        tat[i] = tat[i - 1] + bt[i] - at[i] + at[i - 1];
        waiting_avg += wt[i];
        turnaround_avg += tat[i];
    }

    printf("\nPROCESS\tSYSTEM/USER PROCESS\tBURST TIME\tARRIVAL TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++) {
        printf("\n%d\t\t%d\t\t\t%d\t\t%d\t\t%d\t\t%d", p[i], su[i], bt[i], at[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time is: %f", waiting_avg / n);
    printf("\nAverage Turnaround Time is: %f\n", turnaround_avg / n);

    return 0;
}
