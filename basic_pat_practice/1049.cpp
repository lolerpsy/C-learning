#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, const char *argv[])
{
	int n;
	double sum=0.0,t;
//	double temp=0.0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&t);
//		temp=temp+t*i;
//		sum+=temp;
		sum=sum+t*i*(n-i+1);
	}
	printf("%.2lf\n",sum);
	return 0;
}

