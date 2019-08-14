#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
    string s1, s2 = "0";
    cin >> s1;
    s2 = s2 + s1;
    int flag = 0;
    for (int i = s2.length()-1; i >= 0; i--)
    {
        s2[i] = (s2[i] - '0') * 2 + flag + '0';
        if (s2[i] > '9')
        {
            s2[i] = s2[i] - 10;
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    // cout << s2;
    bool notfun;
    int start;
    if (s2[0] == '0')
        start = 1;
    else
        start = 0;
    for (unsigned i = start; i < s2.length(); i++)
    {
        notfun = true;
        for (unsigned j = 0; j < s1.length(); j++)
        {
            if(s2[i]==s1[j])
            {
                s1[j] = 'a';
                notfun = false;
                break;
            }
        }
        if(notfun)
            break;
    }

    string s(s2, start, s2.length());
    if(!notfun)
        cout << "Yes"
             << "\n"
             << s;
    else
        cout << "No"
             << "\n"
             << s;
    return 0;
}
