#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, const char *argv[])
{
	int a[1001]={0};
	int n,gn,pn,g;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d-%d %d",&gn,&pn,&g);
		a[gn]+=g;
	}
	
	int maxgn=0,maxg=0;
	for(int i=0;i<1001;i++){
		if(a[i]>maxg){
			maxg=a[i];
			maxgn=i;
		}
	}
	printf("%d %d\n",maxgn,maxg);

	return 0;
}

