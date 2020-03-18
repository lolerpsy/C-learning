#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x){return x&(-x);}
using namespace std;
const int maxn=40010;
int a[maxn],b[maxn];
int main(){
    int n,m,k;
    int ma[maxn],mb[maxn];
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            ma[cnt1]++;
        }else if(a[i]==0&&ma[cnt1]!=0){
            cnt1++;
        }
    }
    cnt1++;
    for(int i=0;i<m;i++){
        if(b[i]==1){
            mb[cnt2]++;
        }else if(b[i]==0&&mb[cnt2]!=0){
            cnt2++;
        }
    }
    cnt2++;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(k%i==0){
            ll x=0,y=0;
            for(int j=0;j<cnt1;j++){
                if(ma[j]>=i) x+=ma[j]-i+1;
            }
            for(int j=0;j<cnt2;j++){
                if(mb[j]>=k/i) y+=mb[j]-k/i+1;
            }
            ans+=x*y;
        }
    }
    printf("%lld",ans);
    return 0;
}
