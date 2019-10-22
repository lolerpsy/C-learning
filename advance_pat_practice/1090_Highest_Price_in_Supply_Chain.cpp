#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
vector<int> tree[100010];
int level[100010] = {0};
int maxlevel = 0;
int levelnum[100010] = {0};
void leveltravel(int root){
    queue<int> q;
    q.push(root);
    level[root] = 0;
    while(!q.empty()){
        int t = q.front();
        maxlevel = level[t];
        levelnum[level[t]]++;
        q.pop();
        for(auto v : tree[t]){
            q.push(v);
            level[v] = level[t] + 1;
        }
    }
}
int main(){
    int n;
    double p,r;
    scanf("%d %lf %lf",&n,&p,&r);
    int root;
    for(int i = 0;i<n;i++){
        int t;
        scanf("%d",&t);
        if(t!=-1){
            tree[t].push_back(i);
        }else root =i;
    }
    leveltravel(root);
    printf("%.2lf %d",p*pow(1+0.01*r,maxlevel),levelnum[maxlevel]);

    return 0;
}
