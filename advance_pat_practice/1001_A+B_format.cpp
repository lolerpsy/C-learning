#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
    int a, b;
    cin >> a >> b;
    string s = to_string(abs(a + b));
    if(a+b<0)
    {
        printf("-");
    }

    for (int i = 0; i < s.length(); i ++)
    {
        printf("%c", s[i]);
        if((i%3)==((s.length()-1)%3) && i!=(s.length()-1))
        {
            printf(",");
        }
    }

    return 0;
}
