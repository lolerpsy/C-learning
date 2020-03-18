#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x){return x&(-x);}
using namespace std;
int main(){
    stack<char> s;
    int n;
    scanf("%d",&n);
    getchar();
    ll ans=0;
    int l=0;
    for(int i=0;i<n;i++){
        char t;
        scanf("%c",&t);
        if(t==')') l++;
        else{
            l--;
            if(l>=0) ans+=2;
        }
    }
    if(!l) printf("%d",ans);
    else puts("-1");
    return 0;
}
