#include<cstdio>
using namespace std;
int main(){
    int n,a[10010],dp[10010];
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            dp[i]=1;
            for(int j=1;j<i;j++){
                if(a[i]>=a[j] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>ans) ans=dp[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
