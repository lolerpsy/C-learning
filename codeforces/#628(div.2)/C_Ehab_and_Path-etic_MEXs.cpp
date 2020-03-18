#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x){return x&(-x);}
using namespace std;
const int maxn=100010;
int u[maxn],v[maxn],ind[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&u[i],&v[i]);
        ind[v[i]]++;
        ind[u[i]]++;
    }
    int root=-1,indr=0;
    for(int i=1;i<=n;i++){
        if(ind[i]>=3){
            root=i;indr=ind[i];break;
        }
    }
    if(root==-1){
        for(int i=0;i<n-1;i++){
            printf("%d\n",i);
        }
    }else{
        int cnt=0,x=indr;
        for(int i=0;i<n-1;i++){
            if(u[i]==root || v[i]==root) printf("%d\n",cnt++);
            else printf("%d\n",x++);
        }
    }
    return 0;
}
