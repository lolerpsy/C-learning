#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x) { return x & (-x); }
using namespace std;
int main() {
    int t;
    int a[105];
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a,a+n);
        for(int i=n-1;i>=0;i--){
            printf("%d",a[i]);
            if(i) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
