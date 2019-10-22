#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> gen[110];
int gennum[110]={0};
int level[110]={0,1};
void leveltravel(int root){
    queue<int> q;
    q.push(root);
    gennum[level[root]]++;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = 0;i<gen[t].size();i++){
            q.push(gen[t][i]);
            level[gen[t][i]]=level[t]+1;
            gennum[level[gen[t][i]]]++;
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int fa,k;
        scanf("%d %d",&fa,&k);
        for(int j=0;j<k;j++){
            int t;
            scanf("%d",&t);
            gen[fa].push_back(t);
        }
    }
    leveltravel(1);
    int maxnum=0,maxgen=0;
    for(int i=1;gennum[i]!=0;i++){
        if(gennum[i]>maxnum){
            maxgen = i;
            maxnum = gennum[i];
        }
    }
    printf("%d %d",maxnum,maxgen);
    return 0;
}
