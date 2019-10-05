#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int maxlen = 0;
    for (int i = 0; i < s.length(); i++) {
        int len = 0;
        int t1 = 0;
        while(i -t1 >=0 && i + t1 < s.length() && s[i -t1] == s[i + t1]){
            t1++;
        }
        int t2 = 0;
        while(i - t2>= 0 && i + t2 + 1 < s.length() && s[i - t2] == s[i + t2 + 1]) {
            t2++;
        }
        len = max(t1 * 2 -1, t2 * 2);
        if (len > maxlen) maxlen = len;
    }
    printf("%d\n", maxlen);
    return 0;
}
