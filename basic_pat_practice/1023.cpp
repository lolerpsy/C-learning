#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[10]={0};
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<10;i++){
		if(a[i]!=0) {
			printf("%d",i);
			a[i]--;
			break;
		}
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<a[i];j++){
			printf("%d",i);
		}
	}

	return 0;
}

