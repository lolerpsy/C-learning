#include<iostream>
#include<cstdio>
#include<unordered_set>
#include<algorithm>
using namespace std;
unordered_set<int> s[51];
int main(){
    int n,k;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            int t;
            scanf("%d",&t);
            s[i].insert(t);
        }
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        int nc=0,nt=s[t2].size();
        for(auto it : s[t1]){
            if(s[t2].find(it)==s[t2].end()) nt++;
            else nc++;
        }
        printf("%.1lf%%\n",double(nc)/nt*100);
    }
    return 0;
}
