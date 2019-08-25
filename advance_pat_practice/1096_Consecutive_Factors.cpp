#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    scanf("%lld",&n);
    ll cnt=0,first=0;
    for(ll i=2;(i-1)*(i-1)<=n;i++){
        ll temp=1;
        int j;
        for(j=i;(j-1)*(j-1)<=n;j++){
            temp*=j;
            if(n%temp!=0) break;
        }
        if(cnt<j-i){
            cnt=j-i;
            first=i;
        }
    }
    if(first==0) printf("1\n%lld",n);
    else{
        printf("%lld\n",cnt);
        for(ll i=first;i<first+cnt;i++){
            if(i!=first) printf("*");
            printf("%lld",i);
        }
    }

    return 0;
}
