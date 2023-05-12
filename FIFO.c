#include <stdio.h>
#include <stdbool.h>
void printa(int a[], int n)
{
    for (int i = 0; i < n; i++){printf("%d ", a[i]);}
}

int inframe(int a[], int n, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (v == a[i]){return 1;}
    }
}
int replacee(int a[], int n, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == v){return i;}
    }
}

void fifo(int p[], int n, int f)
{
    int q[n], r = -1, hit = 0, fr = -1;
    int ff[f], c = 0;
    for (int i = 0; i < f; i++){ff[i] = 999;}
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        if (ff[j] == 999)
        {
            ff[j] = p[i];
            q[++r] = p[i];
            j++;
        }
        else if (inframe(ff, f, p[i]) == 1)
        {hit++;}
        else
        {ff[replacee(ff, f, q[++fr])]=p[i];}
        printf("input %d : ",p[i]);
        printa(ff, 3);
    }
    printf("\nTotal hits : %d, Total faults : %d",hit,n-hit);
}
void main()
{
    int pageref[100] = {4, 7, 6, 1, 7, 6, 1, 2, 7, 2};
    int n = 10, fsize = 3;
    fifo(pageref, n, fsize);
}