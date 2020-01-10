#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int degree[510]={0};
int g[510][510]={{0}};
int visit[510]={0};
void dfs(int v){
    visit[v]=1;
    for(int i=1;i<=n;i++){
        if(!visit[i] && g[v][i]==1) dfs(i);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a][b]=g[b][a]=1;
        degree[a]++;
        degree[b]++;
    }
    int cnt=0,evencnt=0,oddcnt=0,flag=1;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            dfs(i);
            cnt++;
        }
    }
    if(cnt>1) flag=0;
    for(int i=1;i<=n;i++){
        if(i!=1) printf(" ");
        printf("%d",degree[i]);
        if(degree[i]%2==0) evencnt++;
        else oddcnt++;
    }
    printf("\n");
    if(flag && oddcnt==0) printf("Eulerian\n");
    else if(flag&&oddcnt==2) printf("Semi-Eulerian\n");
    else printf("Non-Eulerian");
    return 0;
}
