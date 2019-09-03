#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
const int maxn = 10010;
struct node {
  int data;
  struct node *l, *r;
};
int in[maxn], pre[maxn];

node *create(int start, int end, int preroot) {//根据两个序列建树，模板
  if (start > end)
    return NULL;
  int i = start;
  while (i <= end && in[i] != pre[preroot])
    i++;
  node *root = new node;
  root->data = pre[preroot];
  root->l = create(start, i - 1, preroot + 1);
  root->r = create(i + 1, end, preroot + i - start + 1);
  return root;
}
//经典的LCA模板，注意这里返回的应该是节点而不是数据，因为数据是整个int范围，无法判空
node *lca(node *root, int c1, int c2) {
  if (!root) return NULL;
  if (root->data == c1 || root->data == c2) {
    return root;
  }
  node *left = lca(root->l, c1, c2);
  node *right = lca(root->r, c1, c2);
  if (left && right) return root;
  return !left ? right : left;
}

int main(int argc, const char *argv[]) {
  unordered_map<int, int> ma;//用map记录节点数据是否出现过
  int m, n;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    ma[t]++;
    in[i] = t;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &pre[i]);
  }

  node *root = create(0, n - 1, 0);

  for (int i = 0; i < m; i++) {
    int c1, c2;
    scanf("%d %d", &c1, &c2);
    node *common = lca(root, c1, c2);
    if (!common) {
      printf("ERROR: %d and %d are not found.\n", c1, c2);
    } else {
      int ans = common->data;
      if (ans != c1 && ans != c2) {//如果LCA与两者都不同，就说明是两者的LCA
        printf("LCA of %d and %d is %d.\n", c1, c2, ans);
      } else if (ma[c1] != 0 && ma[c2] != 0) {//如果两个key都存在
        int c = (ans == c1 ? c2 : c1);
        printf("%d is an ancestor of %d.\n", ans, c);
      } else {//其中一个key不存在
        int c = (ma[c1] != 0 ? c2 : c1);
        printf("ERROR: %d is not found.\n", c);
      }
    }
  }
  return 0;
}
