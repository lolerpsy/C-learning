#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
typedef struct lnode {
    char data;
    int next;
    bool flag;
} node;
node list[100010];
int main() {
    int n, head1, head2;
    scanf("%d %d %d", &head1, &head2, &n);
    for (int i = 0; i < n; i++) {
        int a, c;
        char b;
        scanf("%d %c %d", &a, &b, &c);
        list[a] = {b, c, false};
    }
    int p = head1;
    while (p != -1) {
        list[p].flag = true;
        p = list[p].next;
    }
    p = head2;
    bool found = false;
    while (p != -1) {
        if (list[p].flag) {
            printf("%05d\n", p);
            found = true;
            break;
        }
        p = list[p].next;
    }
    if (!found) printf("-1\n");
    return 0;
}
