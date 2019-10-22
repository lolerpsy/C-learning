#include<iostream>
#include<cstdio>
using namespace std;
int stripe[10010];
int order[210];
int maxlen=0;
int m,n,l;
void dfs(int now,int noworder,int len){
    if(len>maxlen) maxlen = len;
    if(now>l-1) return;
    if(order[stripe[now]]>0 && order[stripe[now]] >= noworder){
        dfs(now +1,order[stripe[now]],len+1);
        dfs(now+1,noworder,len);
    }else dfs(now+1,noworder,len);
}
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int t;
        scanf("%d",&t);
        order[t]=i+1;
    }
    scanf("%d",&l);
    for(int i=0;i<l;i++){
        scanf("%d",&stripe[i]);
    }
    dfs(0,0,0);
    printf("%d",maxlen);
    return 0;
}
