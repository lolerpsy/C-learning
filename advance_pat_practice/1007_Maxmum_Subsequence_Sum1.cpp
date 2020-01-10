#include<cstdio>
using namespace std;
int main(){
    int n,a[10010],dp[10010],start[10010],end[10010];
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        dp[0]=a[0];
        start[0]=end[0]=0;
        for(int i=1;i<n;i++){
            if(a[i]>=dp[i-1]+a[i]){
                dp[i]=a[i];
                start[i]=end[i]=i;
            }else{
                dp[i]=dp[i-1]+a[i];
                start[i]=start[i-1];
                end[i]=i;
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(dp[i]>dp[ans]){
                ans=i;
            }
        }
        printf("%d %d %d\n",dp[ans]>=0?dp[ans]:0,dp[ans]>=0?a[start[ans]]:a[0],dp[ans]>=0?a[end[ans]]:a[n-1]);
    }
    return 0;
}
