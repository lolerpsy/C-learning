#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[10]={0};
	char t;
	while(scanf("%c",&t)!=EOF){
		a[t-'0']++;
	}
	for(int i=0;i<10;i++){
		if(a[i]!=0) printf("%d:%d\n",i,a[i]);
	}
	return 0;
}

