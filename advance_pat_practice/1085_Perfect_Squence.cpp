#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;
ll a[100010];
int main(){
    int n;
    ll p;
    scanf("%d %lld",&n,&p);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);

    int len=1;
    for(int i=0;i<n;i++){
        int j=upper_bound(a+i+1,a+n,a[i]*p)-a;//找到第一个大于a[i]*p的数
        len=max(len,j-i);//这里j-i是j-1-i+1的结果，也就是a[i]到a[j-1]的长度
    }

    printf("%d\n",len);

    return 0;
}
