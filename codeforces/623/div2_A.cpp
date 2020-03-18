#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    int ans=0;
    while(t--){
        int a,b,x,y;
        scanf("%d %d %d %d",&a,&b,&x,&y);
        ans=max(max(max(a*y,b*x),(a-x-1)*b),(b-y-1)*a);
        printf("%d\n",ans);
    }
    return 0;
}