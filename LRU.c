#include <stdio.h>
#include <stdbool.h>
void printa(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("-");
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

int notframe(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 999)
        {
            return 1;
        }
    }
}
int replacee(int a[], int p[], int n, int f,int l)
{
    int rec[f], recv[f], j = 0, p1 = p[n - 1];
    printf("recplace at %d", p1);
    for (int i = 0; i < f; i++)
    {
        rec[i] = 999;
        recv[i] = 999;
    }
    for (int i = n; i < l; i++)
    {
        if (inframe(a, 3, p[i]) == 1 && inframe(recv, f, p[i]) == 0 && p[i] != p1)
        {
            printf("in");
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
            printf("  m: %d", i);
        }
    }
    printf("\n\n");
    printa(recv, f);
    printa(rec, f);
    printa(a, f);
    printf("\nm:%d-m-1 :%d-infr%d\n", m, recv[m - 1], inframe1(a, f, recv[m]));

    return inframe1(a, f, recv[m]);
}

void fifo(int p[], int n, int f)
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
        if (ff[j] == 999)
        {
            ff[j] = p[i];
            q[++r] = p[i];
            j++;
        }
        else if (inframe(ff, f, p[i]) == 1)
        {
            hit++;
        }
        else
        {
            ff[replacee(ff, p, i, f, n)] = p[i];
        }
        printf("input %d : ", p[i]);
        printa(ff, 3);
    }
    printf("\nTotal hits : %d, Total faults : %d", hit, n - hit);
}
void main()
{
    int pageref[100] = {5, 0, 1, 2, 0, 3, 2, 0, 3, 4, 1, 0, 5, 0, 4, 3, 2, 1, 2, 0, 1};
    int n = 21, fsize = 3;
    fifo(pageref, n, fsize);
}