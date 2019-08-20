#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct mooncake{
    double store,sale,price;
}mcake[1010];

bool comp(mooncake a,mooncake b){
    return a.price>b.price;
}

int main(){
    int n;
    double d;
    scanf("%d %lf",&n,&d);

    for(int i=0;i<n;i++){
        scanf("%lf",&mcake[i].store);
    }

    for(int i=0;i<n;i++){
        scanf("%lf",&mcake[i].sale);
        mcake[i].price=mcake[i].sale/mcake[i].store;
    }

    sort(mcake,mcake+n,comp);

    double total=0,weight=0;
    for(int i=0;i<n;i++){
        if(mcake[i].store<=d){
            total+=mcake[i].store*mcake[i].price;
            weight+=mcake[i].store;
            d=d-mcake[i].store;
        }else{
            total+=d*mcake[i].price;
            break;
        }
    }

    printf("%.2lf\n",total);

    return 0;
}
