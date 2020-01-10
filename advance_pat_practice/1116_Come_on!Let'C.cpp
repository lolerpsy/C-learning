#include<iostream>
#include<cstdio>
using namespace std;
bool isprime(int a){
    if(a<=1) return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    int re[10000]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        re[t]=i+1;
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int query;
        scanf("%d",&query);
        printf("%04d: ",query);
        if(re[query]==0) printf("Are you kidding?\n");
        else if(re[query]==1) printf("Mystery Award\n");
        else if(isprime(re[query])) printf("Minion\n");
        else if(re[query]!=-1) printf("Chocolate\n");
        else if(re[query]==-1) printf("Checked\n");
        if(re[query]!=0) re[query]=-1;
    }
    return 0;
}
