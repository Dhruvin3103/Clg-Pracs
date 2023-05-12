// firstfit

#include <stdio.h>

void first_fit(int pno,int bno, int allocation[],int flags[],int psize[],int bsize[])
{
    int i=0,j=0;
    for (i = 0; i < pno; i++)
        for (j = 0; j < bno; j++)
            if (flags[j] == 0 && bsize[j] >= psize[i])
            {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }
    printf("First Fit \n");
    printf("Block no.\tBlock Size\tProcess No.\t\tProcess Size");
    for (i = 0; i < bno; i++)
    {
        printf("\n%d\t\t%d\t\t", i + 1, bsize[i]);
        if (flags[i] == 1)
            printf("%d\t\t\t%d", allocation[i] + 1, psize[i]);
        else
            printf("Not allocated\t\t-");
    }
}

void main()
{
    int bsize[10]={200,400,600,500,300,250}, psize[10]={357,210,468,491}, bno=6, pno=4, flags[10], allocation[10], i, j;
    for (i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }
    // printf("Enter no. of blocks: ");
    // scanf("%d", &bno);
    // printf("\nEnter size of each block: \n");
    // for (i = 0; i < bno; i++)
    //     scanf("%d", &bsize[i]);
    // printf("\nEnter no. of processes: ");
    // scanf("%d", &pno);
    // printf("\nEnter size of each process: \n");
    // for (i = 0; i < pno; i++)
    //     scanf("%d", &psize[i]);
    first_fit(pno,bno,allocation,flags,psize,bsize);
}