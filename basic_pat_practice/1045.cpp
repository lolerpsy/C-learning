#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(int argc, const char *argv[])
{
	int a[100000];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int b[100000]={0};
	int maxa=0,mina=1e9+1;
	for(int i=0;i<n;i++){
		if(a[i]>maxa) b[i]=1;
		if(a[i]>maxa) maxa=a[i];
	}
	int c[100000];
	int cnt=0;
	for(int i=n-1;i>=0;i--){
//		printf("%d %d %d %d\n",i,a[i],mina);
		if(b[i]==1){
			if(a[i]<mina) b[i]=1;
			else b[i]=0;
		}
		if(a[i]<mina) mina=a[i];
		if(b[i]==1) c[cnt++]=a[i];
	}
	sort(c,c+cnt);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		if(i) printf(" ");
		printf("%d",c[i]);
	}
	printf("\n");
	
	return 0;
}

