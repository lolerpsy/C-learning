#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=210,inf=0x3fffffff;
int n;
int g[maxn][maxn],cost[maxn],happy[maxn];
bool visit[maxn]= {false};
vector<int> pre[maxn];
map<string,int> str2num;
map<int,string> num2str;

void dijkstra(int s) {
	fill(cost,cost+maxn,inf);
	cost[s]=0;
	for(int i=0; i<n; i++) {
		int u=-1,mind=inf;
		for(int j=0; j<n; j++) {
			if(cost[j]<mind && !visit[j]) {
				mind=cost[j];
				u=j;
			}
		}
		if(u==-1) return;
		visit[u]=true;
		for(int v=0; v<n; v++) {
			if(!visit[v] && g[u][v]!=inf) {
				if(g[u][v] + cost[u] < cost[v]) {
					cost[v]=cost[u]+g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if(g[u][v]+cost[u]==cost[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

vector<int> tpath,path;
int num=0,tothappy=0,ahappy=0,thappy=0;
void dfs(int v,int s) {
	if(s==v) {
		num++;
		tpath.push_back(v);
		thappy+=happy[v];
		if(thappy>tothappy) {
			path=tpath;
			tothappy=thappy;
			ahappy=thappy/((int)tpath.size()-1);
		} else if(thappy==tothappy) {
			if(thappy/((int)tpath.size()-1) > ahappy) {
				path=tpath;
				ahappy=thappy/((int)tpath.size()-1);
			}
		}
		tpath.pop_back();
		thappy-=happy[v];
		return;
	}
	tpath.push_back(v);
	thappy+=happy[v];
	for(int i=0; i<pre[v].size() ; i++) {
		dfs(pre[v][i],s);
	}
	tpath.pop_back();
	thappy-=happy[v];
}

int main(int argc, const char *argv[]) {
	fill(g[0],g[0]+maxn*maxn,inf);
	int k;
	string s;
	cin>>n>>k>>s;
	str2num[s]=0;
	num2str[0]=s;
	happy[0]=0;
	for(int i=1; i<n; i++) {
		string t;
		int h;
		cin>>t>>h;
		str2num[t]=i;
		num2str[i]=t;
		happy[i]=h;
	}
	for(int i=0; i<k; i++) {
		string a,b;
		int c;
		cin>>a>>b>>c;
		g[str2num[a]][str2num[b]]=g[str2num[b]][str2num[a]]=c;
	}
	dijkstra(0);
	dfs(str2num["ROM"],str2num[s]);
	printf("%d %d %d %d\n",num,cost[str2num["ROM"]],tothappy,ahappy);
	for(int i=path.size()-1; i>=0; i--) {
		printf("%s",num2str[path[i]].c_str());
		if(i) printf("->");
	}
	return 0;
}
