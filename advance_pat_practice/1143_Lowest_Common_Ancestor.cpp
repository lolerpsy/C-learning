#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<int, int> re;
int pre[10010];
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        re[pre[i]] = 1;
    }
    for (int i = 0; i < m; i++) {
        int c1, c2, ans;
        scanf("%d %d", &c1, &c2);
        for (int j = 0; j < n; j++) {
            ans = pre[j];
            if ((ans <= c2 && ans >= c1) || (ans <= c1 && ans >= c2))
                break;
        }
        if (re[c1] != 1 && re[c2] != 1)
            printf("ERROR: %d and %d are not found.\n", c1, c2);
        else if (re[c1] != 1)
            printf("ERROR: %d is not found.\n", c1);
        else if (re[c2] != 1)
            printf("ERROR: %d is not found.\n", c2);
        else {
            if (ans != c1 && ans != c2)
                printf("LCA of %d and %d is %d.\n", c1, c2, ans);
            else {
                int c = (ans == c1 ? c2 : c1);
                printf("%d is an ancestor of %d.\n", ans, c);
            }
        }
    }
    return 0;
}
