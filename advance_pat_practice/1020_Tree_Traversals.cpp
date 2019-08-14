#include <cstdio>
#include <vector>
using namespace std;

// int find(int a[], int n, int x);
int findmax(int a[], int n, int a1[]);

int main()
{
    int n;
    vector<int> a,a1, b;
    scanf("%d", &n);
    a1.resize(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        a.push_back(t);
        a1[t] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        b.push_back(t);
    }

    while()
    {
        int root;
        root = findmax(b.begin(), n, a1.begin());
    }




    return 0;
}
// int find(int a[], int n, int x)
// {
//     int ret = -1;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] == x)
//         {
//             ret = i;
//             break;
//         }
//     }
//     return ret;
// }

int findmax(int a[],int n,int a1[])
{
    int ret = 0;
    for (int i = 1; i < n;i++)
    {
        if(a1[a[i]]>a1[a[i-1]])
        {
            ret = i;
        }
    }
    return ret;
}
