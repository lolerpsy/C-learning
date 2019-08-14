#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    set<int> m;
    vector<int> v;
    int number;
    int n;
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {

        scanf("%d", &n);
        v.push_back(n);
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                n = (3 * n + 1) / 2;
            }
            m.insert(n);
        }
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 0;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (m.find(*it) == m.end())
        {
            if (cnt)
            printf(" ");
            printf("%d", *it);
            cnt++;
        }
    }

    return 0;
}
