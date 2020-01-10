#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int ropes[10010];
    for(int i=0;i<n;i++){
        scanf("%d",&ropes[i]);
    }
    sort(ropes,ropes+n,less<int>());
    double ans=ropes[0];
    for(int i=1;i<n;i++){
        ans=ans/2+(double)ropes[i]/2;
    }
    printf("%d\n",(int)ans);
    return 0;
}
