#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(int argc, const char *argv[])
{
	int a[100],b[100];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	int cnt=0;
	for(int i=0;i<n-1;i++){
		if(b[i]>b[i+1]){
			cnt=i;
			break;
		}
	}
	bool isin=true;
	for(int i=cnt+1;i<n;i++){
		if(a[i]!=b[i]){
			isin=false;
			break;
		}
	}
	if(isin){
		printf("Insertion Sort\n");
		sort(a,a+cnt+2);
		for(int i=0;i<n;i++){
			if(i) printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
	}else{
		printf("Merge Sort\n");
		bool flag=true;
		int k=1;
		while(flag){
			flag=false;
			for(int i=0;i<n;i++){
				if(a[i]!=b[i]) flag=true;
			}
			k*=2;
			for(int i=0;i<n/k;i++){
				sort(a+i*k,a+(i+1)*k);
			}
			sort(a+n/k*k,a+n);
		}
		for(int i=0;i<n;i++){
			if(i) printf(" ");
			printf("%d",a[i]);
		}
	}

	return 0;
}

