#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int b[100010*2];
unordered_map<ll,ll> s;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        s[b[i]-i]+=b[i];
    }
    ll ans=0ll;
    for(auto v:s){
        ans=max(ans,v.second);
    }
    printf("%lld",ans);
    return 0;
}