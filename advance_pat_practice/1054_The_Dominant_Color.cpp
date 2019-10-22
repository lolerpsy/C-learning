#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
unordered_map<int,int> ma;
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int ans = -1;
    int maxcnt = 0;
    for(int i=0;i<m*n;i++){
        int t;
        scanf("%d",&t);
        ma[t]++;
        if(ma[t]>m*n/2){
            ans = t;
            break;
        }
        if(ma[t]>maxcnt){
            maxcnt=ma[t];
            ans = t;
        }
    }
    printf("%d",ans);
    return 0;
}
