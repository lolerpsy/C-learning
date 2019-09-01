/*
有n件物品，每件物品的重量为W[i]，价值为c[i],现在需要选出若干件物品放入容量为V的容器中，
使得在选入的物品不超过容器的重量的同时，达到价值最大，求最大的价值。(1<=n<=20)
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n,v,w[21],c[21],maxvalue=0;

void dfs(int index,int sumc,int sumw){

    if(index>n || sumw>v) return;//回溯条件

    if(sumw==v){//目标条件
        if(sumc>maxvalue && sumw<=v){
            maxvalue=sumc;
        }
        return;
    }

    if(sumw+w[index]<=v)//剪枝
    {
        dfs(index+1,sumc+c[index],sumw+w[index]);
    }
    dfs(index+1,sumc,sumw);

}

int main(){
    scanf("%d%d",&n,&v);
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }

    dfs(0,0,0);
    printf("%d\n",maxvalue);

    return 0;
}
