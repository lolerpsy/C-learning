#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int n, m;
const int maxn = 10010;
int a[maxn];
vector<int> coins;
bool find1 = false;
int tot = 0;

void dfs(int s, int m) {
  if (s >= n || tot > m || find1)
    return;
  coins.push_back(a[s]);
  tot += a[s];
  if (tot == m) {
    if (find1)
      return;
    find1 = true;
    for (int i = 0; i < coins.size(); i++) {
      if (i)
        printf(" ");
      printf("%d", coins[i]);
    }
    tot -= a[s];
    coins.pop_back();
    return;
  }
  if (tot + a[s] < m)
    dfs(s + 1, m);
  tot -= a[s];
  coins.pop_back();
  dfs(s + 1, m);
}

int main(int argc, const char *argv[]) {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  sort(a, a + n);

  dfs(0, m);

  if (!find1)
    printf("No Solution\n");

  return 0;
}
