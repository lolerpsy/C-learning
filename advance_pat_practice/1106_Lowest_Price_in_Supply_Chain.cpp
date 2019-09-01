#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

vector<vector<int> > v;//链表储存树

int le[100010];
int level(int root){//层次遍历或者叫BFS
    queue<int> q;
    le[root]=0;
    q.push(root);
    while(!q.empty()){
        int t=q.front();
        if(v[t].size()==0) return le[t];//遇到第一个零售商直接返回
        q.pop();
        if(v[t].size()!=0){
            for(int i=0;i<v[t].size();i++){
                le[v[t][i]]=le[t]+1;
                q.push(v[t][i]);
            }
        }
    }
}

int main(){
    int n;
    double p,r;
    scanf("%d %lf %lf",&n,&p,&r);
    v.resize(n);
    int check[100010]={0};
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int t;
            scanf("%d",&t);
            check[t]=1;
            v[i].push_back(t);
        }
    }

    int root=0;
    while(check[root]!=0 && root<n) root++;

    int minle=level(root);

    printf("%.4lf",p*pow(1+0.01*r,minle));

    int cnt=0;
    for(int i=0;i<n;i++){
        if(le[i]==minle && v[i].size()==0) cnt++;
    }

    printf(" %d",cnt);

    return 0;
}
//也可以用dfs来做
