#include<stdio.h>
#include<conio.h>

int waitingtime(float proc[], int n, float burst_time[], float wait_time[])
{
      wait_time[0] = 0;
      for(int i=1;i<n;i++)
      {
      wait_time[i]= burst_time[i-1] + wait_time[i-1];
      }
}

 int turnaroundtime( float proc[], int n, float burst_time[], float wait_time[], float tat[])
{
    for(int i = 0;i < n;i++)
    {
     tat[i] = burst_time[i] + wait_time[i];
    }
}

int avgtime( float proc[], int n, float burst_time[])
{
  float wait_time[n], tat[n], total_wt = 0, total_tat = 0;

   waitingtime(proc, n, burst_time, wait_time);
   turnaroundtime(proc, n, burst_time, wait_time, tat);
    for(int i=0;i<n;i++)
    {
     total_wt = total_wt + wait_time[i];
     total_tat = total_tat + tat[i];
     printf("\nProcess number: %d \n",i);
     printf("Burst time: %f \n",burst_time[i]);
     printf("Wait time: %f \n",wait_time[i]);
     printf("Turn around time: %f \n",tat[i]);
     }

     printf("average waiting time: %f \n",total_wt/n );
     printf("average turn around time: %f \n ",total_tat/n );
}


int main()
{
 float proc[50];
 int n,i;

 float burst_time[50];
 printf("enter the number of processes: \n");
 scanf("%d",&n);
 printf("enter the burst time of each process: \n");
 for(i=0;i<n;i++)
 {
     scanf("%f",&burst_time[i]);
 }

 avgtime(proc,n,burst_time);
}
