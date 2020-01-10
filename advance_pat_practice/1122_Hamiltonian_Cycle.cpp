#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=0x3fffffff;
int g[210][210];
int main(){
    fill(g[0],g[0]+210*210,inf);
    int n,m,k;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a][b]=g[b][a]=1;
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        bool ans=true;
        int re[210]={0};
        int t;
        int first,rfirst;
        scanf("%d %d",&t,&first);
        re[first]=1;
        rfirst=first;
        for(int j=1;j<t;j++){
            int temp;
            scanf("%d",&temp);
            if(j==t-1&&temp!=rfirst) ans=false;
            if(j!=t-1&&re[temp]==1) ans=false;
            re[temp]=1;
            if(g[first][temp]==inf) ans=false;
            first=temp;
        }
        if(t==n+1&&ans&&n!=2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
