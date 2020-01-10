#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=0x3fffffff;
int n,m;
int gl[510][510]={{0}},gt[510][510]={{0}},dist[510],time[510];
bool visit[510]={false};
vector<int> pre[510],pre1[510];
void dijkstra1(int s){
    fill(visit,visit+510,false);
    fill(dist,dist+n,inf);
    dist[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,mind=inf;
        for(int j=0;j<n;j++){
            if(dist[j]<mind && !visit[j]){
                u=j;
                mind=dist[j];
            }
        }
        if(u==-1) return;
        visit[u]=true;
        for(int v=0;v<n;v++){
            if(!visit[v] && gl[u][v]!=inf){
                if(dist[u]+gl[u][v]<dist[v]){
                    dist[v]=dist[u]+gl[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dist[u]+gl[u][v]==dist[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
vector<int> tpath,path;
int t=inf;
void dfs1(int v,int s){
    tpath.push_back(v);
    if(v==s){
        int tt=0;
        for(int i=1;i<tpath.size();i++){
            tt+=gt[tpath[i]][tpath[i-1]];
        }
        if(tt<t){
            path=tpath;
            t=tt;
        }
        tpath.pop_back();
        return;
    }
    for(int i=0;i<pre[v].size();i++){
        dfs1(pre[v][i],s);
    }
    tpath.pop_back();
}
void dijkstra2(int s){
    fill(visit,visit+510,false);
    fill(time,time+n,inf);
    time[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,mind=inf;
        for(int j=0;j<n;j++){
            if(time[j]<mind && !visit[j]){
                u=j;
                mind=time[j];
            }
        }
        if(u==-1) return;
        visit[u]=true;
        for(int v=0;v<n;v++){
            if(!visit[v] && gt[u][v]!=inf){
                if(time[u]+gt[u][v]<time[v]){
                    time[v]=time[u]+gt[u][v];
                    pre1[v].clear();
                    pre1[v].push_back(u);
                }else if(time[u]+gt[u][v]==time[v]){
                    pre1[v].push_back(u);
                }
            }
        }
    }
}
vector<int> tpath1,path1;
int size=inf;
void dfs2(int v,int s){
    tpath1.push_back(v);
    if(v==s){
        if(tpath1.size()<size){
            path1=tpath1;
            size=path1.size();
        }
        tpath1.pop_back();
        return;
    }
    for(int i=0;i<pre1[v].size();i++){
        dfs2(pre1[v][i],s);
    }
    tpath1.pop_back();
}
int main(){
    scanf("%d %d",&n,&m);
    fill(gl[0],gl[0]+510*510,inf);
    fill(gt[0],gt[0]+510*510,inf);
    for(int i=0;i<m;i++){
        int a,b,c,d,e;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        if(c==0){
            gl[a][b]=gl[b][a]=d;
            gt[a][b]=gt[b][a]=e;
        }else{
            gl[a][b]=d;
            gt[a][b]=e;
        }
    }
    int c1,c2;
    scanf("%d %d",&c1,&c2);
    dijkstra1(c1);
    dfs1(c2,c1);
    dijkstra2(c1);
    dfs2(c2,c1);
    if(path==path1){
        printf("Distance = %d; Time = %d: %d",dist[c2],time[c2],path[path.size()-1]);
        for(int i=path.size()-2;i>=0;i--){
            printf(" -> %d",path[i]);
        }
        printf("\n");
    }else{
        printf("Distance = %d: %d",dist[c2],path[path.size()-1]);
        for(int i=path.size()-2;i>=0;i--){
            printf(" -> %d",path[i]);
        }
        printf("\n");
        printf("Time = %d: %d",time[c2],path1[path1.size()-1]);
        for(int i=path1.size()-2;i>=0;i--){
            printf(" -> %d",path1[i]);
        }
    }
    return 0;
}
