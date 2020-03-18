#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 510, inf = 0x3fffffff;
int g[maxn][maxn], cg[maxn][maxn], dist[maxn], cost[maxn] = {0}, pre[maxn];
bool visit[maxn] = {false};
int n;

void dijkstra(int s) {
    fill(dist, dist + maxn, inf);
    fill(cost, cost + maxn, inf);
    dist[s] = 0;
    cost[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, mind = inf;
        for (int j = 0; j < n; j++) {
            if (!visit[j] && dist[j] < mind) {
                u = j;
                mind = dist[j];
            }
        }
        if (u == -1)
            break;
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visit[v] && g[u][v] != inf) {
                if (dist[u] + g[u][v] < dist[v]) {
                    dist[v] = dist[u] + g[u][v];
                    cost[v] = cost[u] + cg[u][v];
                    pre[v] = u;
                } else if (dist[u] + g[u][v] == dist[v]) {
                    if (cost[u] + cg[u][v] < cost[v]) {
                        cost[v] = cost[u] + cg[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void dfs(int v, int s) {
    if (v == s) {
        printf("%d ", v);
        return;
    }
    dfs(pre[v], s);
    printf("%d ", v);
}

int main(int argc, const char *argv[]) {
    fill(g[0], g[0] + maxn * maxn, inf);
    int m, c1, c2;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        g[a][b] = g[b][a] = c;
        cg[a][b] = cg[b][a] = d;
    }

    dijkstra(c1);
    dfs(c2, c1);
    printf("%d %d\n", dist[c2], cost[c2]);

    return 0;
}
