#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int in[35],post[35];
vector<int> levelt[35];
void create(int postl,int postr,int inl,int inr,int level){
    if(postl>postr) return;
    levelt[level].push_back(post[postr]);
    int i=inl;
    while(i<=inr && in[i]!=post[postr]) i++;
    create(postl,postl+(i-inl)-1,inl,i-1,level+1);
    create(postl+(i-inl),postr-1,i+1,inr,level+1);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    for(int i=0;i<n;i++) scanf("%d",&post[i]);
    create(0,n-1,0,n-1,0);
    printf("%d",levelt[0][0]);
    for(int i=1;levelt[i].size()!=0;i++){
        if(i%2==1){
            for(int j=0;j<levelt[i].size();j++){
                printf(" %d",levelt[i][j]);
            }
        }else{
            for(int j=levelt[i].size()-1;j>=0;j--)
                printf(" %d",levelt[i][j]);
        }
    }
    printf("\n");
    return 0;
}
