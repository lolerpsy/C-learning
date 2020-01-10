#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int stripe[10010],order[210]={0},dp[10010];
    int n,m,l,cnt=1;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int t;
        scanf("%d",&t);
        order[t]=i+1;
    }
    scanf("%d",&l);
    for(int i=1;i<=l;i++){
        int t;
        scanf("%d",&t);
        if(order[t]!=0) stripe[cnt++]=order[t];
    }
    int ans=-1;
    for(int i=1;i<=cnt;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(stripe[i]>=stripe[j] && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
            }
        }
        if(dp[i]>ans) ans=dp[i];
    }
    printf("%d",ans);
    return 0;
}
