#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=500,inf=0x3fffffff;
int g[maxn][maxn],cg[maxn][maxn],dist[maxn];
bool visit[maxn];
vector<int> pre[maxn];
int n;

void dijkstra(int s){
	fill(dist,dist+maxn,inf);
	dist[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,mind=inf;
		for(int j=0;j<n;j++){
			if(!visit[j] && dist[j]<mind){
				u=j;
				mind=dist[j];
			}
		}
		if(u==-1) return;
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(!visit[v] && g[u][v]!=inf){
	   			if(dist[u]+g[u][v]<dist[v]){
					dist[v]=dist[u]+g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(dist[u]+g[u][v]==dist[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

int tcost=0,cost=inf;
vector<int> path,tpath;
void dfs(int v,int s){
	if(v==s){
		tpath.push_back(v);
		if(tcost<cost){
			cost=tcost;
			path=tpath;
		}
		tpath.pop_back();
		return;
	}
	
	tpath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		tcost+=cg[pre[v][i]][v];
		dfs(pre[v][i],s);
		tcost-=cg[pre[v][i]][v];
	}
	tpath.pop_back();
}

int main(int argc, const char *argv[])
{
	fill(g[0],g[0]+maxn*maxn,inf);
	int m,c1,c2;
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
	for(int i=0;i<m;i++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		g[a][b]=g[b][a]=c;
		cg[a][b]=cg[b][a]=d;
	}
	
	dijkstra(c1);
	dfs(c2,c1);
	for(int i=path.size()-1;i>=0;i--){
		printf("%d ",path[i]);
	}
	printf("%d %d",dist[c2],cost);

	return 0;
}

