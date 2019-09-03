#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
const int inf=0x3fffffff;
const int maxn=210;
int g[maxn][maxn];

int main(int argc, const char *argv[])
{
	fill(g[0],g[0]+maxn*maxn,inf);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		g[a][b]=g[b][a]=c;
	}
	
	int num;
	scanf("%d",&num);
	int shortest=inf,sid=-1;
	for(int i=0;i<num;i++){
		int k;
		scanf("%d",&k);
		int root;
		scanf("%d",&root);
		
		int dist=0,root1=root;
		set<int> se;
		
		for(int j=1;j<k;j++){
			int t;
			scanf("%d",&t);
			if(g[root][t]==inf){
				dist=-1;
			}else if(g[root][t]!=inf && dist!=-1){
				se.insert(t);
				dist+=g[root][t];
				root=t;
			}
		}
		
		if(dist==-1) printf("Path %d: NA (Not a TS cycle)\n",i+1);
		else if(se.size() != n) printf("Path %d: %d (Not a TS cycle)\n",i+1,dist);
		else if(se.size()==n&& root==root1 && k==n+1){
			printf("Path %d: %d (TS simple cycle)\n",i+1,dist);
			if(dist<shortest){
				shortest=dist;
				sid=i+1;
			}
		}
		else if(se.size() == n && root==root1 && k != n+1){
			printf("Path %d: %d (TS cycle)\n",i+1,dist);
			if(dist<shortest){
				shortest=dist;
				sid=i+1;
			}
		}
	}
	if(shortest!=inf){
		printf("Shortest Dist(%d) = %d",sid,shortest);
	}
	
	return 0;
}

