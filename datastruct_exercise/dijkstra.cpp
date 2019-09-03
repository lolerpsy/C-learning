#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010,inf=0x3fffffff;
int n;
int g[maxn][maxn];
bool visit[maxn]={false};
int dist[maxn],pre[maxn];

void dijkstra(int s){
	fill(dist,dist+maxn,inf);
	dist[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(!visit[j] && dist[j]<min){
				min=dist[j];
				u=j;
			}
		}
		if(u==-1) return;
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(!visit[v] && dist[u]+g[u][v]<dist[v] && g[u][v]!=inf){
				dist[v]=dist[u]+g[u][v];
				pre[v]=u;
			}
		}
	}
}

void dfs(int s,int v){
	if(v==s){
		printf("%d\n",v);
		return;
	}
	dfs(s,pre[v]);
	printf("%d\n",v);
}

int main(int argc, const char *argv[])
{
	fill(g[0],g[0]+maxn*maxn,inf);
	int m,s;
	scanf("%d %d %d",&n,&m,&s);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		g[a][b]=c;
	}
	for(int i=0;i<n;i++){
		g[i][i]=0;
	}
	
	dijkstra(s);
	
	for(int i=0;i<n;i++){
		if(i) printf(" ");
		printf("%d",dist[i]);
	}
	printf("\n");
	dfs(s,5);
	
	return 0;
}

