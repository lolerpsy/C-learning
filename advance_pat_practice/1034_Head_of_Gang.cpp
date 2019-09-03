#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include<map>
#include <vector>

using namespace std;
// const int maxn=1010;
int n, k;
unordered_map<string, unordered_map<string, int>> m;
unordered_map<string, int> v;
unordered_map<string, bool> visit;
map<string,int> gang;

void dfs(string a, int &sum,int &num,string &head) {
  num++;
  visit[a] = true;
  if(v[a]>v[head]) head=a;
  for (auto it = m[a].begin(); it != m[a].end(); it++) {
    sum+=it->second;
    m[it->first][a]=it->second=0;
    if (!visit[it->first]) {
      dfs(it->first, sum ,num , head);
    }
  }
}

int main() {

  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    string t1, t2;
    int t;
    cin >> t1 >> t2 >> t;
    m[t1][t2] += t;
    m[t2][t1] += t;
    visit[t1] = visit[t2] = false;
    v[t1]+=t;
    v[t2]+=t;
  }

  int cnt = 0;
  for (auto it = m.begin(); it != m.end(); it++) {
    int sum=0,num=0;
    string head=it->first;
    dfs(it->first,sum,num,head);
    if(sum>k && num>2){
      cnt++;
      gang[head]=num;
    }

  }
  printf("%d\n", cnt);
  for(auto it=gang.begin();it!=gang.end();it++){
    printf("%s %d\n",it->first.c_str(),it->second);
  }

  return 0;
}
