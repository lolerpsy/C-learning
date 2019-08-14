#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,a;
	int distance[100010]={0};
	int m;
	int sum=0;
	
	int min1[10000];
	int t1,t2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		sum+=a;
		distance[i]=sum;
	}
	int temp;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&t1,&t2);
		if(t1>t2) swap(t1,t2);
		temp=distance[t2-1]-distance[t1-1];
		min1[i]=min(temp,sum-temp);
	}
	for(int i=0;i<m;i++){
		printf("%d\n",min1[i]);
	}

	return 0;
}

