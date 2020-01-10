#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int re[1000010]={0},guest[100010];
int party[10010],ans[10010];
int main(){
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        guest[t1]=t2;
        guest[t2]=t1;
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int t;
        scanf("%d",&t);
        party[i]=t;
        re[t]=1;
    }
    for(int i=0;i<m;i++){
        if(re[party[i]]==re[guest[party[i]]] && re[party[i]]==1) continue;
        else ans[cnt++]=party[i];
    }
    sort(ans,ans+cnt,less<int>());
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        if(i) printf(" ");
        printf("%05d",ans[i]);
    }
    return 0;
}
