#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, const char *argv[])
{
	int a[100000],b[101],c[101]={0};
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		c[a[i]]++;
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&b[i]);
		if(i) printf(" ");
		printf("%d",c[b[i]]);
	}
	return 0;
}

