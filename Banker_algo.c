#include<stdio.h>

int checkarr(int a[],int b[],int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        // printf("|%d-%d|",a[i],b[i]);
        if(a[i]>=b[i]){c++;}
    }
    
    if(c==n){return 0;}
    else{return 1;}
}

int checkdead(int a[],int n)
{
    int d=0;
    for(int i=0;i<n;i++)
    {
        // printf("allow - %d ",a[i]);
        if(a[i]==1){d++;}
    }
    if(n==d){return 0;}
    else{return 1;}
}

int checkallow(int a[],int n)
{
    int d=0;
    for(int i=0;i<n;i++)
    {
        // printf("allow - %d ",a[i]);
        if(a[i]==0){d++;}
    }
    if(n==d){return 0;}
    else{return 1;}
}

int main()
{
 int alloc[100][100], req[100][100],total[100]={10,5,7},remain[100],allow[100];
 int n,i,m;

 printf("Total number of process : ");scanf("%d",&n);
 printf("Total number of resoucre : ");scanf("%d",&m);
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<m;j++)
    {
        printf("process %d has resource %c : ",i+1,j+65);scanf("%d",&alloc[i][j]);
        printf("process %d wants resource %c : ",i+1,j+65);scanf("%d",&req[i][j]);
    }
 }

 for(int i=0;i<m;i++)
 {printf("Total resource of %c : ",i+65);scanf("%d",&total[i]);}
for(int i=0;i<n;i++){allow[i]=1;}
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        req[i][j]=req[i][j]-alloc[i][j];
    }
}
 printf("hi");
 for(int i=0;i<m;i++)
 {
    remain[i]=total[i]-alloc[0][i];
    for(int j=1;j<n;j++)
    {
        remain[i]=remain[i]-alloc[j][i];
    }
 }

i=0;
while(checkallow(allow,n)==1)
{

    // printf("%d\n",checkarr(remain,req[i],m));
    if(checkarr(remain,req[i],m)==0 && allow[i]!=0)
    {
        allow[i]=0;
        for(int j=0;j<m;j++)
        {
            remain[j]=remain[j]+alloc[i][j];
        }
        printf("p%d-->",i);
    }
    // printf("chck : %d\n",checkallow(allow,n));
    i++;
    // printf("-%d-",i);
    if(i==n)
    {
        if(checkdead(allow,n)==0){printf("it will go in deadlock !!");return 0;}
        i=0;
    }
}
for(int i=0;i<m;i++)
 {printf("%d ",remain[i]);}
//  checkarr(alloc[1],req[1],3);
}