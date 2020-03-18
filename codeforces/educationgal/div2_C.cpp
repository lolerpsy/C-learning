#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x){return x&(-x);}
using namespace std;
int main(){
    int t,re[105];
    scanf("%d",&t);
    while (t--){
        fill(re,re+105,0);
        int n;
        ll k;
        scanf("%d %lld",&n,&k);
        for(int i=0;i<n;i++){
            ll x;
            scanf("%lld",&x);
            int cnt=0;
            while(x){
                re[cnt++]+=x%k;
                x/=k;
            }
        }
        int flag=true;
        for(int i=0;i<105;i++){
            if(re[i]>=2){
                flag=false;
                break;
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}
