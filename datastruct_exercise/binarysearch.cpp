#include <iostream>
#include <cstdio>
#include <ctime>

int binaryseach(int a[], int n, int k);

int main(int argc, const char *argv[])
{
    int a[] = {5};
    srand(time(NULL));


    printf("%d\n", binaryseach(a, sizeof(a) / sizeof(a[0]), 5));

    return 0;
}

int binaryseach(int a[], int n, int k)
{
    int ret = -1;
    int left = 0, right = n - 1;
    int mid;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(a[mid] == k)
        {
            ret = mid;
            break;
        }
        else if(a[mid] < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }

    }

    return ret;
}
