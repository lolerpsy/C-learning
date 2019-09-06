#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int n;
int a[1010];
vector<int> path;

void dfs(int root, bool &flag1, bool &flag2) {
  if (root > n)
    return;
  if (root * 2 > n) {
    path.push_back(a[root]);
    for (int i = 0; i < path.size(); i++) {
      if (i > 0) {
        if (path[i] < path[i - 1])
          flag1 = false;
        if (path[i] > path[i - 1])
          flag2 = false;
      }
      if (i != 0)
        printf(" ");
      printf("%d", path[i]);
    }
    printf("\n");
    path.pop_back();
    return;
  }
  path.push_back(a[root]);
  if (root * 2 + 1 <= n) {
    dfs(root * 2 + 1, flag1, flag2);
  }
  dfs(root * 2, flag1, flag2);
  path.pop_back();
}

int main() {

  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  bool flag1 = true, flag2 = true;
  dfs(1, flag1, flag2);
  if (flag1 || flag2) {
    if (a[1] > a[n])
      printf("Max Heap\n");
    else
      printf("Min Heap\n");
  } else {
    printf("Not Heap\n");
  }

  return 0;
}
