#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
bool visit[1010];
int g[1010][1010];
void BFS(int v,const int n);
int main(int argc, const char *argv[])
{
	int n,m,k;
	int check[1000];
	scanf("%d %d %d",&n,&m,&k);
	
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		g[a][b]=g[b][a]=1;
	}
	
	for(int i=0;i<k;i++){
		scanf("%d",&check[i]);
	}

	for(int i=0;i<k;i++){
		fill(visit,visit+1010,false);
		visit[check[i]]=true;
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!visit[j]){
				BFS(j,n);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}

	return 0;
}

void BFS(int v,const int n){
	queue<int> q;
	q.push(v);
	visit[v]=true;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(!visit[i] && g[t][i]==1){
				visit[i]=true;
				q.push(i);
			}
		}
	}
		
}//注意重复入队的问题，先访问后入队，队内都是已访问节点

