include<stdio.h>
#include<stdlib.h>

 void main()
 {
      int n,p[50],bt[50],wt[50],tt[50];
      int i,j,temp;
      printf("enter the number of processes: \n");
      scanf("%d",&n);

      printf("enter the burst time of each process: \n");
      for(i=0;i<n;i++)
      {
          scanf("%d",&bt[i]);
      }
      //sorting burst time
      for(i=0;i<n;i++)
      {
     
       temp = bt[i];
       for(j=i+1;j<n;j++)
      {
          if(bt[j]<temp)
          {
              temp = bt[j];
              bt[j] = bt[i];
              bt[i] = temp;

          }
      }
      }
     
      for(i=0;i<n;i++)
      {
          printf("%d \t",bt[i]);
      }

     

      // waiting time of processes

      for(i=0;i<n;i++)
      {
          if(i == 0)
          {
              wt[i] = 0;
          }
          else
          {
          wt[i] = wt[i-1]+bt[i-1];
          }
         
      }
     

      // turn around time
      for(i=0;i<n;i++)
      {
          tt[i] = bt[i] + wt[i];
         
      }
     //final result
     for(i=0;i<n;i++)
     {
         printf("\n process:%d \nburst time:%d \nwaiting time:%d \nturnaround time:%d \n",i,bt[i],wt[i],tt[i]);
     }
      //average waiting time
      float aw=0;
      for(i=0;i<n;i++)
      {
          aw += wt[i];
      }
      aw = aw/n;
      printf("\naverage waiting time is %f \n",aw);

      //average turnaround time
      float at = 0;
      for(i=0;i<n;i++)
      {
          at += tt[i];
      }
      at = at/n;
      printf("\naverage turnaround time is %f \n",at);
 }
