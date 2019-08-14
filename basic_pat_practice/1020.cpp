#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct mooncake{
	double store,sale,price;
}mcake;

bool comp(mcake a,mcake b){
	return a.price>b.price;
}

int main(int argc, char const *argv[])
{
	int n,d;
	scanf("%d %d",&n,&d);
	vector<mcake> v;
	mcake t;
	for(int i=0;i<n;i++){
		scanf("%lf",&t.store);
		v.push_back(t);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&v[i].sale);
		v[i].price=v[i].sale/v[i].store;
	}
	sort(v.begin(),v.end(),comp);
	double sum=0;
	for(int i=0;i<n;i++){
		if(d<=v[i].store){
			sum+=d*v[i].price;
			break;
		}else{
			sum+=v[i].sale;
			d=d-v[i].store;
		}
	}
	printf("%.2f",sum);
	return 0;
}

