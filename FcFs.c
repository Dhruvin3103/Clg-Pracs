#include <stdio.h>
#include <stdlib.h>

double avg(int a[], int n) 
{
    int sum = 0;
    for (int i=0;i<n;i++) {sum += a[i];}
    return (double)sum/(double)n;
}

int main() 
{
    int AT[] = {2, 5, 1, 0, 4};
    int bT[] = {6, 2, 8, 3, 4};
    int n = sizeof(AT) / sizeof(AT[0]);
    int ganttC[n+1],ganttP[n];
    ganttC[0] = 0;
    int dict[n][3];
    int CT = bT[0];
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        dict[i][0] = AT[i];
        dict[i][1] = bT[i];
        dict[i][2] = i;
    }
    for(int i =0;i<n;i++)
    // {printf("%d ",dict[i][2]);}
    // printf("\n");
    for (int i=0;i<n;i++) 
    {
        for (int j=i+1;j<n;j++) 
        {
            if(dict[i][0] > dict[j][0]) 
            {
                int temp1 = dict[i][0];
                int temp2 = dict[i][1];
                int temp3 = dict[i][2];
                dict[i][0] = dict[j][0];
                dict[i][1] = dict[j][1];
                dict[i][2] = dict[j][2];
                dict[j][0] = temp1;
                dict[j][1] = temp2;
                dict[j][2] = temp3;
            }
        }
    }

    for (int i=0;i<n;i++) 
    {
        ganttP[i]=dict[i][2]+1;
        ganttC[i+1] =sum + dict[i][1];
        sum =sum + dict[i][1];
    }

    int taT[n], wT[n];
    for (int i = 0; i < n; i++) {taT[i] =ganttC[i+1] - AT[i];}

    for (int i = 0; i < n; i++) {wT[i] = taT[i] - bT[i];}

    double avgWT = avg(wT,n);
    double avgTAT = avg(taT,n);
    printf("Gantt Chart : \n");
    for(int i =0;i<n;i++)
    {printf("   p%d",ganttP[i]);}
    printf("\n");
    for(int i =0;i<n+1;i++)
    {printf(" %d  ",ganttC[i]);}
    printf("\nAverage timing : %f \nWaiting Time : %f", avgTAT, avgWT);
    return 0;
}