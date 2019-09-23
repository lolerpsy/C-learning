#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
double price, r;//价格和涨价率
typedef struct lnode {//树节点
    int k;
    vector<int> child;
    int num;
    int level;
} node;
node tree[100010];
bool visit[100010] = {false};

double leveltravel(int root) {//层序遍历
    double ans = 0.0;
    queue<int> q;//千万不要用节点队列，就用下标队列，会产生意想不到的bug
    q.push(root);
    visit[root] = true;
    tree[root].level = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (tree[v].k == 0) {
            ans += price * tree[v].num * pow(0.01 * r + 1, tree[v].level);
        } else {
            for (int i = 0; i < tree[v].k; i++) {
                visit[tree[v].child[i]] = true;
                tree[tree[v].child[i]].level = tree[v].level + 1;//层序加一
                q.push(tree[v].child[i]);
            }
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d %lf %lf", &n, &price, &r);
    for (int i = 0; i < n; i++) {//建树
        int ki;
        scanf("%d", &ki);
        tree[i].k = ki;
        if (ki == 0) {
            scanf("%d", &tree[i].num);
        } else {
            for (int j = 0; j < ki; j++) {
                int t;
                scanf("%d", &t);
                tree[i].child.push_back(t);
            }
        }
    }
    double ans = leveltravel(0);
    printf("%.1lf", ans);
    return 0;
}
