#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
    string s;
    int p, t;

    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        map<char, int> m;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
            if (s[i] == 'P')
                p = i;
            if (s[i] == 'T')
                t = i;
        }
        if (m['P'] == 1 && m['T'] == 1 && m['A'] != 0 && t - p > 1 && m.size() == 3 && p * (t - p - 1) == s.length() - t - 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
