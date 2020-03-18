#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,n,d;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&d);
        int high=n*(n-1)/2;
        int low=0;
        int h=0,num=1;
        while(num*2-1<n){
            low+=h*num;
            num*=2;
            h++;
        }
        low+=h*(n-num+1);
        if(d<low || d>high) {printf("NO\n"); continue;}
        vector<int> fa(n+1,1);
        for(int i=2;i<=n;i++){
            fa[i]=i-1;
        }
        vector<int> numofch(n+1,1);
        numofch[n]=0;
        vector<int> depth(n+1);
        for(int i=0;i<=n;i++){
            depth[i]=i-1;
        }
        vector<int> checked(n+1,0);
        int cur=high;
        while(cur!=d){
            int v=-1;
            for(int i=2;i<=n;i++){
                if(checked[i]==1) continue;
                if(numofch[i]==0 && (v==-1 || depth[i]<depth[v])){
                    v=i;
                }
            }
            int p=-1;
            for(int i=1;i<=n;i++){
                if(numofch[i]<2 && depth[i]==depth[v]-2){
                    p=i;
                }
            }
            if(p==-1){
                checked[v]=1;
                continue;
            }
            numofch[p]++;
            numofch[fa[v]]--;
            fa[v]=p;
            depth[v]--;
            cur--;
        }
        printf("YES\n");
        for(int i=2;i<=n;i++){
            printf("%d%s",fa[i],i==n?"\n":" ");
        }
    }
    return 0;
}