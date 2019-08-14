#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    int a[54] = {0};
    int af[54];
    for (int i = 0; i < 54; i++)
    {
        a[i] = i;
    }

    int time;
    scanf("%d", &time);
    int shuffle[54];
    for (int i = 0; i < 54; i++)
    {
        scanf("%d", &shuffle[i]);
    }

    while (time--)
    {
        for (int i = 0; i < 54; i++)
        {
            af[shuffle[i] - 1] = a[i];
        }
        for (int i = 0; i < 54; i++)
        {
            a[i] = af[i];
        }
    }

    for (int i = 0; i < 54; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        int t = a[i] / 13;
        switch (t)
        {
        case 0:
            printf("S");
            break;
        case 1:
            printf("H");
            break;
        case 2:
            printf("C");
            break;
        case 3:
            printf("D");
            break;
        case 4:
            printf("J");
            break;
        }

        printf("%d", (a[i] % 13) + 1);
    }
    return 0;
}
