#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cctype>
using namespace std;
const int maxn=1050,inf=0x3fffffff;
int g[maxn][maxn],dist[maxn];
int n,m,k,ds;
bool visit[maxn];

int tonum(string s){
	if(isdigit((s[0]))) return stoi(s);
	else return n + stoi(s.substr(1));
}

void dijkstra(int s){
	fill(visit,visit+maxn,false);
	fill(dist,dist+maxn,inf);
	dist[s]=0;
	for(int i=1;i<=n+m;i++){
		int u=-1,mind=inf;
		for(int j=1;j<=n+m;j++){
			if(dist[j]<mind && !visit[j]){
				u=j;
				mind=dist[j];
			}
		}
		if(u==-1) return;
		visit[u]=true;
		for(int v=1;v<=n+m;v++){
			if(!visit[v] && g[u][v]!=inf){
				if(dist[u]+g[u][v]<dist[v]){
					dist[v]=dist[u]+g[u][v];
				}
			}
		}
	}
}

int main(int argc, const char *argv[])
{
	fill(g[0],g[0]+maxn*maxn,inf);
	scanf("%d %d %d %d",&n,&m,&k,&ds);
	for(int i=1;i<=n+m;i++){
		g[i][i]=0;
	}
	for(int i=0;i<k;i++){
		string s1,s2;
		int c;
		cin>>s1>>s2>>c;
		int a=tonum(s1),b=tonum(s2);
		if(c<g[a][b]) g[a][b]=g[b][a]=c;
	}
	
	int ansid=-1,ansmin=0;
	double anstot=inf;
	for(int i=n+1;i<=n+m;i++){
		dijkstra(i);
		int tansid=i,tmin=inf;
		double tot=0.0;
		for(int j=1;j<=n;j++){
			if(dist[j]>ds){
				tansid=-1;
				break;
			}else{
				if(dist[j]<tmin) tmin=dist[j];
				tot+=1.0*dist[j];
			}
		}
		if(tansid==-1) continue;
		if(tmin>ansmin){
			ansid=tansid;
			ansmin=tmin;
			anstot=tot;
		}else if(tmin==ansmin && tot<anstot){
			ansid=tansid;
			anstot=tot;
		}
	}
	if(ansid==-1) printf("No Solution");
	else printf("G%d\n%d.0 %.1lf",ansid-n,ansmin,anstot/n);

	return 0;
}

