#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	char s;
	scanf("%d %c",&n,&s);
	int cnt;
	for(cnt=0;2*cnt*cnt-1<=n;cnt++)
		;
	cnt--;
	for(int i=cnt;i>0;i--){
		for(int j=0;j<cnt-i;j++){
			printf(" ");
		}
		for(int j=0;j<i*2-1;j++){
			printf("%c",s);
		}
		printf("\n");
	}
	for(int i=0;i<cnt-1;i++){
		for(int j=cnt-1-i-1;j>0;j--){
			printf(" ");
		}
		for(int j=0;j<2*i+3;j++){
			printf("%c",s);
		}
		printf("\n");
	}
	printf("%d",n-2*cnt*cnt+1);
	return 0;
}

