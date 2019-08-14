#include<iostream>
#include<vector>
using namespace std;

int main(int argc, const char *argv[])
{
    int n,t,time = 0;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &t);
        v.push_back(t);
    }
    time += 6 * (v[0] - 0);
    for (int i = 1; i < n; i ++)
    {
        if(v[i] - v[i-1] > 0)
        {
            time += 6 * (v[i] - v[i - 1]);
        }
        else
        {
            time += 4 * abs(v[i] - v[i - 1]);
        }
    }

    printf("%lu",(v.size() * 5 + time));

    return 0;
}
