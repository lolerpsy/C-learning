#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<int> v;
    int cnt = 0;
    v.push_back(2);
    scanf("%d", &n);

    int flag=2;

    for (int i = 3; i <= n; i++)
    {
        bool isprime = 1;
        for (auto x : v)
        {
            if (i % x == 0)
            {
                isprime = 0;
                break;
            }
            if (x * x > i)
                break;
        }
        if (isprime)
        {
            if(i-flag==2)
                cnt++;
            flag = i;
            v.push_back(i);
        }
    }
    printf("%d\n", cnt);
    return 0;
}
