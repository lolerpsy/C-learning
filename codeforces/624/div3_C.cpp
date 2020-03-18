#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    int ans[26]={0};
    char combo[100010*2];
    int p[100010*2],times[100010*2];
    scanf("%d",&t);
    while (t--){
        fill(ans,ans+26,0);
        scanf("%d%d",&n,&m);
        fill(times,times+n,0);
        scanf("%s",combo+1);
        for(int i=0;i<m;i++){
            scanf("%d",&p[i]);
        }
        sort(p,p+m);
        for(int i=0;i<m;i++){
            times[p[i]]+=1;
        }
        times[n]=1;
        ans[combo[n]-'a']=1;
        for(int i=n-1;i>=1;i--){
            times[i]+=times[i+1];
            ans[combo[i]-'a']+=times[i];
        }
        for(int i=0;i<26;i++){
            if(i!=0) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }

    return 0;
}