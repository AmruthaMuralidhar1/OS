//Multilevel queue schedulling

#include<stdio.h>
#include<stdlib.h>
main()
{
int p[30],bt[30], su[30], wt[30],tat[30],i, k, n, temp;
float waiting_avg, turnaround_avg;
int tr;
int csource=0;
int cuser=0;
int btsource[30],btuser[30],puser[30],psource[30];
printf("Enter the number of processes : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("System process/User Process (0/1) : ");
scanf("%d", &tr);
printf("Enter the Burst Time of Process %d : ", i);
if(tr==1){
 scanf("%d",&btuser[cuser]);
puser[cuser]=i;
cuser++;
}
else if(tr==0){
scanf("%d",&btsource[csource]);
psource[csource]=i;
csource++;
}
}
for(i=0;i<csource;i++){
	   p[i]=psource[i];
    bt[i]=btsource[i];
    su[i]=0;
}
for(i=0;i<cuser;i++){

     p[i+csource]=puser[i];
    bt[i+csource]=btuser[i];
   su[i+csource]=1;
}
for(i=0;i<n;i++){
		printf("%d %d",p[i],bt[i]);

}
waiting_avg = wt[0] = 0;
turnaround_avg = tat[0] = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
waiting_avg = waiting_avg + wt[i];
turnaround_avg = turnaround_avg + tat[i];
}
printf("\nPROCESS\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
for(i=0;i<n;i++)
printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],su[i],bt[i],wt[i],tat[i]);
printf("\nAverage Waiting Time is    : %f",waiting_avg/n);
printf("\nAverage Turnaround Time is :%f\n",turnaround_avg/n);

}
