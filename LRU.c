#include<stdio.h>

int inframe(int f[], int n, int v)
{
    for(int i=0;i<n;i++)
    {
        if(f[i]==v)
            return 1;
    }
    return 0; 
}

int replace(int d[], int f[], int nf, int pos)
{
    int max[3]={0},ind;
    for(int i=0;i<nf;i++)
    {
        for(int j=pos;j>=0;j--)
        {
            if(d[j]==f[i] && (pos-j)>max[i])
            {
                max[i] = pos-j;
                break;
            }
        }
    }
    int maxs=0;
    for(int i=0;i<nf;i++)
    {
        if(max[i]>maxs){
            ind =i;
            maxs=max[i];}
    }
    return ind;
}

void main()
{
    int data[]={4 , 7, 6, 1, 7, 6, 1, 2, 7, 2};
    int n =sizeof(data)/sizeof(data[0]);
    int nf = 3;
    int frame[100],j=0,hit=0;
    for(int i=0;i<nf;i++)
    {frame[i]=-1;}
    
    for(int i=0;i<n;i++)
    {
        if(inframe(frame,nf,data[i])==1)
        {
            hit++;
        }
        else if(j<nf)
        {
            frame[j++]=data[i];
        }
        else
        {
            frame[replace(data,frame,nf,i)]=data[i];
        }
        printf("%d -> ",data[i]);
        for(int i=0;i<nf;i++)
        {printf("%d ",frame[i]);}
        printf("\n");
    }
    printf("\n hits are %d",hit);
}
