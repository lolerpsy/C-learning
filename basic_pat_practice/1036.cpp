#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	char s;
	int row;
	scanf("%d %c",&n,&s);
	if(n%2==1) row=n/2+1;
	else row=n/2;
	for(int i=0;i<row;i++){
		if(i==0||i==row-1){
			for(int j=0;j<n;j++){
				printf("%c",s);
			}
			printf("\n");
		}else{
			printf("%c",s);
			for(int j=1;j<n-1;j++){
				printf(" ");
			}
			printf("%c\n",s);
		}
	}

	return 0;
}

