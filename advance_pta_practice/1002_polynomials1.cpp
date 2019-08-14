#include <cstdio>
using namespace std;

int main()
{
    const float delta = 1e-7;
    float a[1100] = {0};
    int number;
    int cnt = 0;
    int tempi;
    float temp;
    for (int i = 0; i < 2;i++)
    {
        scanf("%d", &number);
        for (int j = 0; j < number;j++)
        {
            scanf("%d %f", &tempi,&temp);
            a[tempi] += temp;
        }
    }

    for (int i = 0; i < 1100;i ++)
    {
        if(a[i])
        {
            cnt++;
        }
    }

    printf("%d", cnt);

    for (int i = 1099; i >=0; i -- )
    {
        if(a[i]>delta || a[i]<(-1*delta))
        {
            printf(" %d %.1f", i ,a[i]);
        }

    }
        return 0;
}
