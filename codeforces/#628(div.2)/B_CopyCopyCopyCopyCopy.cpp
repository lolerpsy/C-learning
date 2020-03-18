#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x){return x&(-x);}
using namespace std;
unordered_set<int> s;
const int maxn=100010*2;
int a[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        s.clear();
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            s.insert(a[i]);
        }
        printf("%d\n",s.size());
    }
    return 0;
}
