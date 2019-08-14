#include <cstdio>

using namespace std;

int main()
{
    const float delta = 1e-7;
    int m, n;
    float a[1001] = {0}, b[1001] = {0}, c[2001] = {0};

    int tempi;
    float temp;

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %f", &tempi, &temp);
        a[tempi] = temp;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %f", &tempi, &temp);
        b[tempi] = temp;
    }

    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < 2001; i++)
    {
        if (c[i]<(-1*delta)||c[i]>delta)
        {
            cnt++;
        }
    }
    printf("%d", cnt);

    for (int i = 2000; i >= 0; i--)
    {
        if (c[i]<(-1*delta) || c[i]>delta)
            printf(" %d %.1f", i, c[i]);
    }

    return 0;
}
