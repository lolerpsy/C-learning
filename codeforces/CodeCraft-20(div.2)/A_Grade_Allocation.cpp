#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x){return x&(-x);}
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int sum=0,x;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            sum+=x;
        }
        printf("%d\n",sum>=m?m:sum);
    }
    return 0;
}
