#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;

string add(string a,string b){
    string s=a;
    int flag=0;
    for(int i=a.length()-1;i>=0;i--){
        if(a[i]-'0'+b[i]-'0'+flag<10){
            s[i]=a[i]+b[i]-'0'+flag;
            flag=0;
        }else{
            s[i]=a[i]+b[i]-'0'+flag-10;
            flag=1;
        }
    }
    if(flag) s="1"+s;
    return s;
}

int main(){
    ll n,k;
    scanf("%lld %lld",&n,&k);

    ll i;
    string s=to_string(n);
    for(i=0;i<=k;i++){
        string s1,s2;
        s1=s2=s;
        reverse(s2.begin(),s2.end());
        if(s1==s2 || i==k) break;
        s=add(s1,s2);
    }
    cout<<s<<endl<<i;

    return 0;
}
