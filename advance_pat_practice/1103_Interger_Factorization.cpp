#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int n,k,p,maxfacsum=-1;

vector<int> fac,ans,tempans;

void init(){
    int t=0;
    while(pow(t,p)<=n){
        fac.push_back(pow(t,p));
        t++;
    }
}

void dfs(int index,int nowk,int nowsum,int facsum){

    if(nowsum>n || nowk>k || index<1) return;//回溯条件

    if(nowk==k && nowsum==n){//目标条件
        if(facsum>maxfacsum){
            ans=tempans;
            maxfacsum=facsum;
        }
        return;
    }

    if(nowsum+fac[index]<=n){//剪枝
        tempans.push_back(index);//选择fac[index]的分支,把index压入临时数组
        dfs(index,nowk+1,nowsum+fac[index],facsum+index);
        tempans.pop_back();//回溯时把index pop掉，准备进行不选择index的分支
    }
    dfs(index-1,nowk,nowsum,facsum);//不选择index的分支

}

int main(){
    scanf("%d %d %d",&n,&k,&p);

    init();
    dfs(fac.size()-1,0,0,0);

    if(maxfacsum==-1){
        printf("Impossible\n");
    }else{
        printf("%d = ",n);
        for(int i=0;i<k;i++){
            if(i) printf(" + ");
            printf("%d^%d",ans[i],p);
        }
    }

    return 0;
}
