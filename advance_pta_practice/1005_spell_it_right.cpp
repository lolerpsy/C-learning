#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
    string a[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    string s;
    cin >> s;
    int sum = 0;
    for (auto l : s)
    {
        sum += (l - '0');
    }

    string s1 = to_string(sum);
    for (int i = 0; i < s1.length(); i++)
    {
        printf("%s", a[s1[i] - '0'].c_str());
        if (i < s1.length() - 1)
        {
            printf(" ");
        }
    } 

    return 0;
}
