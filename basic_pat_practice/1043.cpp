#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, const char *argv[])
{
	int a[7]={0};
    char t;
	while(scanf("%c",&t)!=EOF){
		switch(t){
			case 'P':
				a[0]++;
				break;
			case 'A':
				a[1]++;
				break;
			case 'T':
				a[2]++;
				break;
			case 'e':
				a[3]++;
				break;
			case 's':
				a[4]++;
				break;
			case 't':
				a[5]++;
				break;
		}
	}
	while(!(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0)){
		if(a[0]>0){
			printf("P");
			a[0]--;
		}
		if(a[1]>0){
			printf("A");
			a[1]--;
		}
		if(a[2]>0){
			printf("T");
			a[2]--;
		}
		if(a[3]>0){
			printf("e");
			a[3]--;
		}
		if(a[4]>0){
			printf("s");
			a[4]--;
		}
		if(a[5]>0){
			printf("t");
			a[5]--;
		}
	}
	printf("\n");
	return 0;
}

