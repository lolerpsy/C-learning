#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <vector>


using namespace std;
int n, maxdepth = 0;
vector<int> g[10010];
vector<int> path;
bool visit[10010] = {false};
void dfs(int v, int depth) {
    if (depth > maxdepth) {
        maxdepth = depth;
        path.clear();
        path.push_back(v);
    } else if (depth == maxdepth) {
        path.push_back(v);
    }
    visit[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        if (!visit[g[v][i]]) {
            dfs(g[v][i], depth + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    set<int> s;
    int s1, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            dfs(i, 1);
            s1 = path[0];
            for (int j = 0; j < path.size(); j++) {
                s.insert(path[j]);
            }
            cnt++;
        }
    }
    if (cnt > 1)
        printf("Error: %d components", cnt);
    else {
        fill(visit, visit + 10010, false);
        path.clear();
        dfs(s1, 1);
        for (int i = 0; i < path.size(); i++) {
            s.insert(path[i]);
        }
        for (auto v : s) {
            printf("%d\n", v);
        }
    }

    return 0;
}
