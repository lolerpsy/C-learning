#include<cstdio>
#include<vector>
using namespace std;
int g[210][210]={{0}};
int main(){
    int nv,ne,m;
    scanf("%d %d",&nv,&ne);
    for(int i=0;i<ne;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a][b]=g[b][a]=1;
    }
    scanf("%d",&m);
    vector<int> vs;
    for(int i=0;i<m;i++){
        vs.clear();
        int k;
        scanf("%d",&k);
        int re[210]={0};
        bool flag=true;
        for(int j=0;j<k;j++){
            int t;
            scanf("%d",&t);
            if(!flag) continue;
            re[t]=1;
            for(auto v:vs){
                if(g[t][v]==0){
                    flag=false;
                    break;
                }
            }
            vs.push_back(t);
        }
        if(!flag){
            printf("Not a Clique\n");
            continue;
        }
        bool flag1=true;
        for(int j=1;j<=nv;j++){
            bool flag2=false;
            if(re[j]==0){
                flag2=true;
                for(auto v:vs){
                    if(g[j][v]==0) flag2=false;
                }
            }
            if(flag2){
                flag1=false;
                break;
            }
        }
        printf("%s\n",flag1?"Yes":"Not Maximal");
    }

    return 0;
}
