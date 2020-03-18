#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x){return x&(-x);}
using namespace std;
int main(){
   int n,m;
   scanf("%d%d",&n,&m);
   ll a[100010*2];
   for(int i=0;i<n;i++){
       scanf("%lld",&a[i]);
   }
   if(n>m) printf("0");
   else{
       ll ans=1;
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               ans*=(abs(a[i]-a[j])%m);
               ans%=m;
           }
       }
       printf("%lld",ans%m);
   }
   return 0;
}
