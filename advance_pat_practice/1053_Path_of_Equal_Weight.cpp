#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,s,sum=0;
int weight[110];
vector<int> tree[110];
bool comp(int a,int b) {return weight[a]>weight[b];}
vector<int> path;
void dfs(int root){
    sum += weight[root];
    path.push_back(root);
    if(tree[root].size()==0){
        if(sum == s){
            for(int i=0;i<path.size();i++){
                if(i) printf(" ");
                printf("%d",weight[path[i]]);
            }
            printf("\n");
        }
        path.pop_back();
        sum -= weight[root];
        return;
    }
    for(int i=0;i<tree[root].size();i++){
        dfs(tree[root][i]);
    }
    sum-=weight[root];
    path.pop_back();
}
int main(){
    scanf("%d %d %d",&n,&m,&s);
    for(int i=0;i<n;i++){
        scanf("%d",&weight[i]);
    }
    for(int i=0;i<m;i++){
        int id,k;
        scanf("%d %d",&id,&k);
        for(int i=0;i<k;i++){
            int t;
            scanf("%d",&t);
            tree[id].push_back(t);
        }
    }
    for(int i=0;i<n;i++){
        sort(tree[i].begin(),tree[i].end(),comp);
    }
    dfs(0);
    return 0;
}
