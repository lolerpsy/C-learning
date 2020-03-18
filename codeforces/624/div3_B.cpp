#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    int a[105],p[105];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&p[i]);
        }
        while(true){
            bool flag=true;
            for(int i=0;i<m;i++){
                if(a[p[i]-1]>a[p[i]]) {
                    swap(a[p[i]-1],a[p[i]]);
                    flag=false;
                }
            }
            if(flag) break;
        }
        if(is_sorted(a,a+n)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}