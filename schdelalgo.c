#include <stdio.h>
int main()
{
    int x[10], i, j, smallest, count = 0, time, ctr = 1, n, pid[10], a[10], b[10];
    int gp[100] = {1};
    int gid[100] = {1};
    double wat = 0, tt = 0, end, tat[10], wt[10], ct[10];
    printf("enter the number of Processes : ");
    scanf("%d", &n);
    // n = 5;
    printf("enter process no.s : ");
    for (i = 0; i < n; i++)
        scanf("%d", &pid[i]);
    // int pid[n] = {1, 2, 3, 4, 5};
    printf("enter arrival time for all process : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    // int a[n] = {2, 5, 1, 0, 4};
    printf("enter burst time for all process : ");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    // int b[n] = {6, 2, 8, 3, 4};
    for (i = 0; i < n; i++)
        x[i] = b[i];
    b[9] = 9999;
    int procprev = 0;
    int gl = 0;
    for (time = 0; count != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (a[i] <= time && b[i] < b[smallest] && b[i] > 0)
            {
                smallest = i;
            }
        }
        gid[0] = 1;
        gp[0] = a[0];
        if (smallest != procprev)
        {
            gid[ctr] = smallest + 1;
            gp[ctr] = time;
            ctr++;
        }
        procprev = smallest;
        b[smallest]--;
        if (b[smallest] == 0)
        {
            count++;
            end = time + 1;
            wat = wat + end - a[smallest] - x[smallest];
            tt = tt + end - a[smallest];
            tat[smallest] = end - a[smallest];
            wt[smallest] = end - a[smallest] - x[smallest];
            if (count == n)
            {
                gp[ctr] = time + 1;
                ctr++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {ct[i] = tat[i] + a[i];}
    printf("\nGantt Chart: \n");
    for (int i = 0; i < ctr - 1; i++)
    {printf("     P%d\t", gid[i]);}
    printf("\n");
    for (int i = 0; i < ctr; i++)
    {printf("%d\t ", gp[i]);}
    printf("\n\n");
    printf("Process\tArrival Time\tBurst Time  Completion Time  Turn Around Time\t  Waiting Time\n");
    printf("------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {printf("  %d\t    %d\t\t   %d\t\t%lf\t%lf\t\t%lf\n", pid[i], a[i], x[i], ct[i], tat[i], wt[i]);}
    printf("Average Turnaround time = %f\n", tt/n);
    printf("Average waiting time = %f\n", wat/n);
    return 0;
}