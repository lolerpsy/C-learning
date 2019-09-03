#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=510,inf=0x3fffffff;
int g[maxn][maxn],dist[maxn];
vector<int> pre[maxn];
int weight[maxn];
bool visit[maxn]={false};

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
			if(!visit[v] && g[u][v]!=inf && dist[u]+g[u][v]<dist[v]){
				dist[v]=dist[u]+g[u][v];
				pre[v].clear();
				pre[v].push_back(u);
			}else if(!visit[v] && g[u][v]!=inf && dist[u]+g[u][v]==dist[v]){
				pre[v].push_back(u);
			}
		}
	}
}
int num=0,wtot=0;
vector<int> path,temppath;
void dfs(int v,int s){
	if(v==s){
		num++;
		temppath.push_back(v);
		int w=0;
		for(int i=temppath.size()-1;i>=0;i--){
			w+=weight[temppath[i]];
//			printf("%d",temppath[i]);
//			if(i) printf(" ");
		}
//		printf("\n");
		if(w>wtot){
			wtot=w;
			path=temppath;
		}
		temppath.pop_back();
		return;
	}
	
	temppath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		dfs(pre[v][i],s);
	}
	temppath.pop_back();
}

int main(int argc, const char *argv[])
{
	fill(g[0],g[0]+maxn*maxn,inf);
	int m,c1,c2;
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
		g[i][i]=0;
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		g[a][b]=g[b][a]=c;
	}

	dijkstra(c1);
	
	dfs(c2,c1);
	
	printf("%d %d",num,wtot);

	return 0;
}

