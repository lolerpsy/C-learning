#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
const int inf = 0x3fffffff;
unordered_map<string, unordered_map<string, int>> g;
unordered_map<string, int> hg, dist;
unordered_map<string, bool> visit;
unordered_map<string, vector<string>> pre;
int n;
void dijkstra(string s) {
  dist[s] = 0;
  for (int i = 0; i < n; i++) {
    string u = "";
    int mind = inf;
    for (auto it = dist.begin(); it != dist.end(); it++) {
      if (it->second < mind && !visit[it->first]) {
        u = it->first;
        mind = it->second;
      }
    }
    if (u == "")
      return;
    visit[u] = true;
    for (auto it = g[u].begin(); it != g[u].end(); it++) {
      if (!visit[it->first]) {
        if (g[u][it->first] + dist[u] < dist[it->first]) {
          dist[it->first] = dist[u] + g[u][it->first];
          pre[it->first].clear();
          pre[it->first].push_back(u);
        } else if (g[u][it->first] + dist[u] == dist[it->first]) {
          pre[it->first].push_back(u);
        }
      }
    }
  }
}

int thappy = 0, maxhappy = 0, num = 0, ahappy = 0;
vector<string> tpath, path;
void dfs(string v, string s) {
  if (s == v) {
    num++;
    thappy += hg[v];
    tpath.push_back(v);
    if (thappy > maxhappy) {
      maxhappy = thappy;
      path = tpath;
      ahappy = maxhappy / (path.size() - 1);
    } else if (thappy == maxhappy && thappy / (tpath.size() - 1) > ahappy) {
      path = tpath;
      ahappy = maxhappy / (path.size() - 1);
    }
    thappy -= hg[v];
    tpath.pop_back();
    return;
  }
  tpath.push_back(v);
  thappy += hg[v];
  for (auto it = pre[v].begin(); it != pre[v].end(); it++)
    dfs(*it, s);
  tpath.pop_back();
  thappy -= hg[v];
}

int main(int argc, const char *argv[]) {
  int k;
  string s;
  cin >> n >> k >> s;
  hg[s] = 0;
  for (int i = 1; i < n; i++) {
    int t;
    string st;
    cin >> st >> t;
    dist[st] = inf;
    visit[st] = false;
    hg[st] = t;
  }
  for (int i = 0; i < k; i++) {
    int t;
    string a, b;
    cin >> a >> b >> t;
    g[a].insert(pair<string, int>(b, t));
    g[b].insert(pair<string, int>(a, t));
  }
  dijkstra(s);
  dfs("ROM", s);
  printf("%d %d %d %d\n", num, dist["ROM"], maxhappy, ahappy);
  for (int i = path.size() - 1; i >= 0; i--) {
    printf("%s", path[i].c_str());
    if (i)
      printf("->");
  }
  return 0;
}
