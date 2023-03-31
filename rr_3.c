#include <stdio.h>
#include <stdlib.h>

int rear = -1, front = -1, queue[100], max = 20;

// int max()

void enque(int val)
{
   if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = val;
}

int deque()
{
    int val = queue[front];
    // printf("deque = %d, ",val+1);
    if (front == -1)
    {
        return -1;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return val;
}

int main()
{
    int gc[100],n,c=0,ct=0,i=0,x[6],t=0,tq=4,j=0;
    float avg=0.0;
    int com[100],tAT[100],wAT[100];
    int comp[100];
    printf("Enter the number of process : ");
    scanf("%d",&n);
    int b[100],a[100];
    // int b[n] = {5,6,3,1,5,4};
    // int a[n] = {0,1,2,3,4,6};
    for(int l=0;l<n;l++)
    {
        printf("Enter the arrival and burst time for p%d : ",l);
        scanf("%d %d",&a[l],&b[l]);
    }
    
    enque(i);
    int r = 0;
    for(int i=0;i<6;i++){x[i]=b[i];}
    gc[ct]=0;
    
    // printf("gc : %d \n",gc[ct-1]);
    while(c!=n)
    {
        int d = deque();
        int d1 =d;
        if(b[d]<=tq)
        {
            gc[++ct]=gc[ct]+b[d];
            com[j++]=d;
            t=t+b[d];
            b[d]=0;
            comp[d]=t;
            c++;
            while(a[r+1]<=t && r<=n)
            {
                if(b[r+1]!=0)
                {
                    enque(d+1);
                }
                r++;
            }
            
        }
        else if(b[d]>tq)
        {
            gc[++ct]=gc[ct]+tq;
            com[j++]=d;
            t=t+tq;
            b[d]=b[d]-tq;
            while(a[r+1]<=t && r<=n)
            {
                if(b[r+1]!=0)
                {
                    enque(r+1);
                }
                r++;
            }
            enque(d1);
        }
        
    }
    printf("Gantt Chart : \n");
    for(int i=0;i<j;i++)
    {
        printf("     P%d\t",com[i]+1);
    }printf("\n");
    for(int i=0;i<ct+1;i++)
    {
        printf("%d\t ",gc[i]);
    }printf("\n");
    for(int i=0;i<6;i++)
    {
        tAT[i]=comp[i]-a[i];
        wAT[i]=tAT[i]-x[i];
    }
    printf("Process\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, a[i], x[i], comp[i], tAT[i], wAT[i]);
    }
    for(int i=0;i<n;i++)
    {
        avg=avg+wAT[i];
    }
    printf("Average waiting time : %f \n",avg/n);
    avg=0;
    for(int i=0;i<n;i++)
    {
        avg=avg+tAT[i];
    }
    printf("Average waiting time : %f",avg/n);
}