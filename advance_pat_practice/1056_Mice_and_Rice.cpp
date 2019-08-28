#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct micestruct{
    int weight,rank;
}mice;

int main(){
    int np,ng;
    scanf("%d %d",&np,&ng);

    vector<mice> m(np);

    for(int i=0;i<np;i++){
        scanf("%d",&m[i].weight);
    }

    queue<int> q;
    for(int i=0;i<np;i++){
        int t;
        scanf("%d",&t);
        q.push(t);
    }

    int group=(np%ng==0 ? np/ng : np/ng+1);
    int num=np;
    while(1){
        for(int i=0;i<group;i++){
            int maxg=q.front();
            for(int j=i*ng;j<i*ng+ng && j<num;j++){
                if(m[q.front()].weight>m[maxg].weight) maxg=q.front();
                m[q.front()].rank=group+1;
                q.pop();
            }
            q.push(maxg);
        }
        if(group==1){
            m[q.front()].rank=1;
            break;
        }
        num=group;
        group=(group%ng==0 ? group/ng : group/ng+1);
    }

    for(int i=0;i<np;i++){
        if(i) printf(" ");
        printf("%d",m[i].rank);
    }

    return 0;
}
