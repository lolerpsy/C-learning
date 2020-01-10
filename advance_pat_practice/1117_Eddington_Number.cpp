#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int re[100010]={0};
    int n,e=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&re[i]);
    }
    sort(re+1,re+n+1,greater<int>());
    while(e<=n && re[e]>e) e++;
    printf("%d",e-1);
    return 0;
}
