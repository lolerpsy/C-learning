#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s.length() == 3)
    {
        for (int i = 0; i < (*(s.begin()) - '0'); i++)
            printf("B");
        for (int i = 0; i < (*(s.begin() + 1) - '0'); i++)
            printf("S");
    }
    if (s.length() == 2)
        for (int i = 0; i < (*(s.begin()) - '0'); i++)
            printf("S");
    for (int i = 1; i <= (*(s.end() - 1) - '0'); i++)
        printf("%d", i);
    return 0;
}
