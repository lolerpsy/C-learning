#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > v(30);
int post[31],in[31];

void create(int root,int start,int end,int index){
    if(start>end) return;
    int i=start;
    while(i<end && post[root]!=in[i]) i++;
    v[index].push_back(post[root]);
    create(root-1-end+i,start,i-1,index+1);
    create(root-1,i+1,end,index+1);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&post[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    create(n-1,0,n-1,0);

    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i].size()!=0){
            for(int j=0;j<v[i].size();j++){
                if(cnt) printf(" ");
                printf("%d",v[i][j]);
                cnt++;
            }
        }
    }
    return 0;
}
