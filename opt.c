#include <stdio.h>
#include <stdbool.h>
void printa(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int inframe(int a[], int n, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (v == a[i])
        {
            return 1;
        }
    }
    return 0;
}

int inframe1(int a[], int n, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (v == a[i])
        {
            return i;
        }
    }
}

int replacee(int a[], int p[], int n, int f,int l)
{
    int rec[f], recv[f], j = 0, p1 = p[n - 1];
    for (int i = 0; i < f; i++)
    {
        rec[i] = 999;
        recv[i] = 999;
    }
    for (int i = n; i <=l; i++)
    {
        if (inframe(a, f, p[i]) == 1 && inframe(recv, f, p[i]) == 0)
        {
            rec[j] = i-n;
            recv[j] = p[i];
            j++;
        }
    }
    int m = rec[0], pos;
    for (int i = 0; i < f; i++)
    {
        if (rec[i] > m && rec[i] != 999)
        {
            m = i;
        }
    }

    return inframe1(a, f, recv[m]);
}

int checkafter(int a[],int b[],int s,int n,int f)
{
    int c=0,nf=0;
    for(int i=0;i<f;i++)
    {
        c=0;
        for(int j=s;j<n;j++)
        {
            // printf("\n%d-%d\n",b[i],a[j]);
            if(b[i]==a[j])
            {c++;}
        }
        // printf("%d,%d-",c,i);
        if(c==0){return i;}
    }
    return -1;
}
void opt(int p[], int n, int f)
{
    int q[n], r = -1, hit = 0, fr = -1;
    int ff[f], c = 0;
    for (int i = 0; i < f; i++)
    {
        ff[i] = 999;
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        if (inframe(ff, f, p[i]) == 1)
        {
            hit++;
        }
        else if(checkafter(p,ff,i,n,f)!=-1)
        {
            // printf("in");
            ff[checkafter(p,ff,i,n,f)]=p[i];
        }
        else if (ff[j] == 999)
        {
            ff[j] = p[i];
            q[++r] = p[i];
            j++;
        }
        else
        {
            ff[replacee(ff, p, i, f,n)] = p[i];
        }
        printf("input %d : ", p[i]);
        printa(ff, f);
    }
    printf("\nTotal hits : %d, Total faults : %d", hit, n - hit);
}
void main()
{
    int pageref[] = {1, 2, 3, 4, 2, 1, 5, 3, 2, 4, 6};
    int n = sizeof(pageref) / sizeof(pageref[0]), fsize = 3;
    opt(pageref, n, fsize);
}