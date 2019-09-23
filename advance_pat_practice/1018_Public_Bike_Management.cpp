#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 510, inf = 0x3fffffff;
int c, n, sp, m;
int g[maxn][maxn], dist[maxn], weight[maxn];
bool visit[maxn] = {false};
vector<int> pre[maxn];

void dijkstra(int s) {
    fill(dist, dist + maxn, inf);
    dist[s] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, mind = inf;
        for (int j = 0; j <= n; j++) {
            if (dist[j] < mind && !visit[j]) {
                mind = dist[j];
                u = j;
            }
        }
        if (u == -1)
            return;
        visit[u] = true;
        for (int v = 0; v <= n; v++) {
            if (!visit[v] && g[u][v] != inf) {
                if (dist[u] + g[u][v] < dist[v]) {
                    dist[v] = dist[u] + g[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dist[u] + g[u][v] == dist[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

vector<int> tpath, path;
int send = -inf, back;

void dfs(int v) {
    if (v == 0) {
        int tot = 0, tmin = inf, tback;
        for (int i = tpath.size() - 1; i >= 0; i--) {
            tot += (weight[tpath[i]] - c / 2);
            if (tot < tmin)
                tmin = tot;
        }
        if (tmin > 0)
            tmin = 0;
        tback = tot + abs(tmin);
        if (tmin > send) {
            path = tpath;
            send = tmin;
            back = tback;
        } else if (tmin == send && tback < back) {
            path = tpath;
            back = tback;
        }
        return;
    }

    tpath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    tpath.pop_back();
}

int main(int argc, const char *argv[]) {
    fill(g[0], g[0] + maxn * maxn, inf);
    scanf("%d %d %d %d", &c, &n, &sp, &m);
    for (int i = 0; i <= n; i++) {
        g[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = g[b][a] = c;
    }
    dijkstra(0);

    dfs(sp);
    printf("%d 0", abs(send));
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("->%d", path[i]);
    }
    printf(" %d", back);

    return 0;
}
