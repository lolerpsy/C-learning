#include <bits/stdc++.h>
typedef long long ll;
int n;
int a[105],s[105];
inline int lowbit(int x){return x&(-x);}
int getsum(int k){
    int ret=0;
    while(k>0){
        ret+=s[k];
        k-=lowbit(k);
    }
    return ret;
}
void update(int k,int v){
    while(k<=n){
        s[k]+=v;
        k+=lowbit(k);
    }
}
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        fill(s+1,s+n+1,0);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            update(i,a[i]);
        }
        bool flag=false;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if((getsum(i)-getsum(j))%2==0){
                    printf("%d\n%d",i-j,j+1);
                    for(int x=j+2;x<=i;x++){
                        printf(" %d",x);
                    }
                    printf("\n");
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) printf("-1\n");
    }
    return 0;
}
