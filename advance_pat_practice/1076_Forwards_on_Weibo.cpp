#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=10010;

vector<int> g[maxn];//使用数组会内存
bool visit[maxn]={false};
int n,l;

void bfs(int v,int &num){//bfs，num可以作为引用参数或者返回值都可以
  queue<int> q;
  queue<int> le;//用于记录层数的双生队列，用结构体记录当前v和layer也可以
  le.push(0);
  visit[v]=true;
  q.push(v);
  while(!q.empty()){
    int t=q.front();
    int tl=le.front();
    if(tl>l) return;
    le.pop();
    q.pop();
    num++;
    for(int i=0;i<g[t].size();i++){
      if(!visit[g[t][i]]){
        visit[g[t][i]]=true;
        q.push(g[t][i]);
        le.push(tl+1);
      }
    }
  }

}

int main(){
  scanf("%d %d",&n,&l);
  for(int i=1;i<=n;i++){
    int m;
    scanf("%d",&m);
    for(int j=0;j<m;j++){
      int a;
      scanf("%d",&a);
      g[a].push_back(i);//注意是信息是从被关注传递到关注者即 a -> i
    }
  }

  int k;
  scanf("%d",&k);
  for(int i=0;i<k;i++){
    int query;
    scanf("%d",&query);
    fill(visit,visit+maxn,false);//多次查询一定记得重置visit数组
    int num=0;
    bfs(query,num);
    printf("%d\n",num-1);
  }

  return 0;
}
