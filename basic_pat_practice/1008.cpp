#include <cstdio>

using namespace std;

void re(int a[], int front, int rear)
{
    int temp;
    for (int i = 0; i < (rear - front + 1) / 2; i++)
    {
        temp = a[front + i];
        a[front + i] = a[rear - i];
        a[rear - i] = temp;
    }
}

int main()
{
    int a[100];
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    m = m % n;
    re(a, n - m, n - 1);
    re(a, 0, n - m - 1);
    re(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}
