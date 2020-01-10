#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int father[10010]={0};
int findfather(int a){
    int t=a;
    while(father[a]>0){
        a=father[a];
    }
    while(father[t]>0){
        int p=t;
        t=father[t];
        father[p]=a;
    }
    // printf("a=%d\n",a);
    return a;
}
void setunion(int a,int b){
    int fa=findfather(a);
    int fb=findfather(b);
    if(fa!=fb) {
        if(father[fa]>father[fb]){
            father[fb]+=father[fa];
            father[fa]=fb;
        }
        else{
            father[fa]+=father[fb];
            father[fb]=fa;
        }
    }
}
int main(){
    fill(father,father+10010,-1);
    int n,maxnum=0;
    scanf("%d",&n);
    for(int i=1;i<n+1;i++){
        int k,first;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int t;
            scanf("%d",&t);
            if(t>maxnum) maxnum=t;
            if(j==0) first=t;
            setunion(first,t);
        }
    }
    int anscnt=0,ans=0;
    for(int i=1;i<=maxnum;i++){
        if(father[i]<0){
            anscnt++;
            ans+=(-1*father[i]);
        }
    }
    printf("%d %d\n",anscnt,ans);
    int query;
    scanf("%d",&query);
    for(int i=0;i<query;i++){
        int x1,x2;
        scanf("%d %d",&x1,&x2);
        if(findfather(x1)==findfather(x2)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
