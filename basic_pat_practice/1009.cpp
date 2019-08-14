#include<algorithm>
#include<string>
#include <stack>
#include<iostream>
using namespace std;

int main()
{
    stack<string> v;
    string t;

    while(cin >> t)
        v.push(t);

    cout << v.top();
    v.pop();
    while(!v.empty())
    {
        cout << " " << v.top();
        v.pop();
    }
    return 0;
}
