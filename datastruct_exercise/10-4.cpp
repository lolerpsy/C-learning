#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, const char *argv[])
{
	int a[51]={0};
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		a[t]++;
	}
	for(int i=0;i<51;i++){
		if(a[i]) printf("%d:%d\n",i,a[i]);
	}

	return 0;
}

