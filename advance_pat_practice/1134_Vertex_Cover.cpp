#include<cstdio>
#include<vector>
using namespace std;
int main(){
    vector<int> v[10010];
    int n,m,k;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(i);
        v[b].push_back(i);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        bool visit[10010]={false};
        int nv;
        scanf("%d",&nv);
        for(int j=0;j<nv;j++){
            int t;
            scanf("%d",&t);
            for(int l=0;l<v[t].size();l++){
                visit[v[t][l]]=true;
            }
        }
        bool flag=false;
        for(int j=0;j<m;j++){
            if(!visit[j]){
                flag=true;
                break;
            }
        }
        printf("%s\n",flag?"No":"Yes");
    }
    return 0;
}
