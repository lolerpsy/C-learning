#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int p1[1001] = {0}, p2[1001] = {0}, ps[1001] = {0}, pp[2001] = {0};
    int n1, n2;
    int tempa, tempn;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d %d", &tempa, &tempn);
        p1[tempn] = tempa;
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d %d", &tempa, &tempn);
        p2[tempn] = tempa;
    }

    for (int i = 0; i < 1001; i++)
    {
        ps[i] = p1[i] + p2[i];
    }

    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            pp[i + j] += p1[i] * p2[j];
        }
    }

    int cnts = 0, cntp = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (ps[i] != 0)
        {
            cnts++;
        }
    }

    for (int i = 0; i < 2001; i++)
    {
        if (pp[i] != 0)
        {
            cntp++;
        }
    }

    if (cntp == 0)
        printf("0 0");
    int k1 = 0, k2 = 0;
    for (int i = 2000; i >= 0; i--)
    {
        if (pp[i] != 0)
        {
            printf("%d %d", pp[i], i);
            k1++;
            if (k1 < cntp)
            printf(" ");
        }

    }

    printf("\n");
    if (cnts == 0)
        printf("0 0");
    for (int i = 1000; i >= 0; i--)
    {
        if (ps[i] != 0)
        {
            printf("%d %d", ps[i], i);
            k2++;
            if (k2 < cnts)
            printf(" ");
        }

    }

    return 0;
}
