#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        int price[2];
        int p;
        scanf("%d%d%d",&price[0],&price[1],&p);
        string s;
        cin>>s;
        s=s[0]+s;
        ll dp[s.size()];
        dp[s.size()-1]=price[s[s.size()-1]-'A'];
        int begin=s.size()-2;
        if(s[s.size()-2]!=s[s.size()-1]){
            dp[s.size()-2]=dp[s.size()-1]=price[s[s.size()-2]-'A'];
            begin--;
        }
        for(int i=begin;i>=1;i--){
            if(s[i]!=s[i+1]){
                dp[i]=dp[i+1]+price[s[i]-'A'];
            }else{
                dp[i]=dp[i+1];
            }
        }
        int ans=s.size()-1;
        for(int i=1;i<s.size();i++){
            if(dp[i]<=p){
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}