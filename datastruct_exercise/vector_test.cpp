#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> a(10);
    for (int i = 0; i < 10;i ++)
    {
        a[i] = i;
    }

    a.erase(a.begin() + 3);

    for (auto i : a)
    {
        printf("%d\n", i);
    }

    string s = "0000000001234";
    string s1 = "0000000001235";

    printf("%d", (s < s1));



    return 0;
}
