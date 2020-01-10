#include<cstdio>
using namespace std;
const int maxn=100;
int dp[maxn]={0,1,};
int F(int n){
    if(dp[n]!=-1) return dp[n];
    else{
        dp[n]=F(n-1)+F(n-2);
        return dp[n];
    }
}
int main(){
    int n;
    for(int i=2;i<100;i++) dp[i]=-1;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",F(n));
    }
    return 0;
}
