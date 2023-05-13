#include<stdio.h>

int minburst(int b[], int a[],int n, int t, int v[])
{
    int min =9999,minind;
    for(int i=0;i<n;i++)
    {
        if(min>b[i] && a[i]<=t && v[i]==0 && b[i]>0)
        {
            min = b[i];
            minind = i;
        }
    }
    return minind;
}

void main()
{
    // int pri[] = {5,4,3,2,2};
    int pro[] = {1,2,3,4,5};
    int at[] = {3,1,4,0,2};
    int bt[] = {1,4,2,6,3},obt[100];
    int ct[100],tat[100],wat[100],pgant[100],cgant[100],vis[100]={0};
    int n = sizeof(pro)/sizeof(pro[0]);
    int t=0,co=0,ind=0,minind=0,atat=0,awat=0;
    for(int i=0;i<n;i++)
    {obt[i]=bt[i];}
    while(co<n)
    {

        int minind = minburst(bt,at,n,t,vis);
        printf("p%d ",pro[minind]);
        t=t+bt[minind];
        ct[minind]=t;
        bt[minind]=0;
        vis[minind]=1;
        co++;
    }
    
    for(int i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        atat= atat+tat[i];
        wat[i] = tat[i] - obt[i];
        awat = awat + wat[i];
    }
    printf("\npro\tarr\tbur\tcom\ttat\twat\t\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",pro[i],at[i],obt[i],ct[i],tat[i],wat[i]);
    }
    
    printf("avg turn around time %f \n",(float)atat/n);
    printf("avg waiting time %f ",(float)awat/n);
}
