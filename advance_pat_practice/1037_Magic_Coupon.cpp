#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

bool comp(int a,int b){
    return a>b;
}
long long coup[100010],coun[100010],prop[100010],pron[100010];
int main(){
    int nc,np;
    int cntcp=0,cntcn=0,cntpp=0,cntpn=0;

    scanf("%d",&nc);
    for(int i=0;i<nc;i++){
        long long t;
        scanf("%lld",&t);
        if(t>0) coup[cntcp++]=t;
        else if(t<0) coun[cntcn++]=t;
    }

    scanf("%d",&np);
    for(int i=0;i<np;i++){
        long long t;
        scanf("%lld",&t);
        if(t>0) prop[cntpp++]=t;
        else if(t<0) pron[cntpn++]=t;
    }

    long long sum=0;
    sort(coup,coup+cntcp,comp);
    sort(coun,coun+cntcn);
    sort(prop,prop+cntpp,comp);
    sort(pron,pron+cntpn);

    for(int i=0;i<min(cntcp,cntpp);i++){
        sum+=coup[i]*prop[i];
    }

    for(int i=0;i<min(cntcn,cntpn);i++){
        sum+=coun[i]*pron[i];
    }

    printf("%lld\n",sum);

    return 0;
}
//4 2 1
//7 6
//-1
//-3 -2
