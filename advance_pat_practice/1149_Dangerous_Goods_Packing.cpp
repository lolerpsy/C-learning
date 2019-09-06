#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  unordered_map<int, vector<int>> have;//大的哈希表，用链表解决冲突
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    have[a].push_back(b);
    have[b].push_back(a);
  }

  for (int i = 0; i < m; i++) {
    int ship[1010];
    unordered_map<int, bool> hash1;//查询数组的哈希表
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &ship[j]);
      hash1[ship[j]] = true;
    }
    bool flag = true;
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < have[ship[j]].size(); l++) {
        if (hash1[have[ship[j]][l]])
          flag = false;
      }
    }
    if (flag)
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}
