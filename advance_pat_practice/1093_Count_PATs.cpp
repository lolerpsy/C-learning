#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

const long long mod=1000000007;
int main(){
    string s;
    int cntt=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='T') cntt++;
    }

    long long num=0;
    int tempp=0,tempt=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='P') tempp++;
        else if(s[i]=='T') tempt++;
        else{
            num+=(tempp%mod)*((cntt-tempt)%mod);
            num%=mod;
        }
    }

    printf("%lld\n",num);

    return 0;
}
