#include<stdio.h>

int main()
{
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], i, j, temp = 0, n;
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i] = i;
    }

    printf("Enter the arrival time for each process: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter the burst time for each process: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    // Sorting processes based on arrival time
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n - i - 1); j++)
        {
            if (at[j] > at[j + 1])
            {
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;
                
                temp = at[j + 1];
                at[j + 1] = at[j];
                at[j] = temp;
                
                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // Calculating completion time (ct)
    ct[0] = at[0] + bt[0];

    for (i = 1; i < n; i++)
    {
        int idleTime = 0;
        
        if (ct[i - 1] < at[i])
        {
            idleTime = at[i] - ct[i - 1];
        }

        ct[i] = ct[i - 1] + bt[i] + idleTime;
    }

    // Calculating turnaround time (tat) and waiting time (wt)
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        
        atat += tat[i];
        awt += wt[i];

        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    atat = atat / n;
    awt = awt / n;

    printf("\nAverage turnaround time: %f", atat);
    printf("\nAverage waiting time: %f\n", awt);

    return 0;
}
