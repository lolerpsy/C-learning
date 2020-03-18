#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x){return x&(-x);}
using namespace std;
int main(){
   int t;
   scanf("%d",&t);
   while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n<5) printf("NO\n");
        else{
            printf("%s\n",n%m==0?"YES":"NO");
        }
   }
   return 0;
}
