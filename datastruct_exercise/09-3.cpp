#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, const char *argv[])
{
	int a[1010];
	int b[1010];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	int cnt=0;
	for(int i=0;i+1<n;i++){
		if(b[i]>b[i+1]){
			cnt=i;
			break;
		}
	}
	int j=cnt+1;
	for(int i=j;i<n;i++){
		if(b[i]==a[i]) j=i;
		else break;
	}
	if(j==n-1){
		printf("Insertion Sort\n");
		sort(a,a+cnt+2);
		for(int i=0;i<n;i++){
			if(i) printf(" ");
			printf("%d",a[i]);
		}
	}else{
		printf("Heap Sort\n");
		sort(a, a + n);
		int cnt1=n-1;
		for(int i=n-1;i>=0;i--){
			if(b[i]!=a[i]){
				cnt1=i;
				break;
			}
		}
		int maxit = b[0];
		int temp = b[cnt1];
		int parent,child;
		for (parent = 0; parent * 2 <= cnt1-1;parent=child){
			child = parent * 2+1;
			if((child!=cnt1-1) &&b[child]<b[child+1]){
				child++;
			}
			if(temp>=b[child])
				break;
			else{
				b[parent] = b[child];
			}
		}
		b[parent] = temp;
		b[cnt1] = maxit;
		for(int i=0;i<n;i++){
			if(i) printf(" ");
			printf("%d",b[i]);
		}
	}


	return 0;
}

