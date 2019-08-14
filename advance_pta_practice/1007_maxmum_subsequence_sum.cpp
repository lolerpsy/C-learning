#include <cstdio>

using namespace std;

int main(int argc, const char *argv[])
{
    int len;
    int thissum = 0, maxsum = 0;
    int a[10000];
    int head = 0, tail = 0, count = 0;
    bool allnegative = true;
    bool zeroflag = true;
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < len; i++)
    {
        if (a[i] >= 0)
        {
            allnegative = false;
        }

        thissum += a[i];

        if (thissum > maxsum)
        {
            maxsum = thissum;
            zeroflag = false;
            tail = i;
            head = count;
        }

        if (thissum < 0)
        {
            thissum = 0;
            count = i + 1;
        }
    }
    if (allnegative)
        printf("%d %d %d", maxsum, a[0], a[len - 1]);
    else if (zeroflag)
        printf("%d 0 0", maxsum);
    else
        printf("%d %d %d", maxsum, a[head], a[tail]);
    return 0;
}
