#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	const int maxnum=1001;
	int a[maxnum]={0},b[maxnum]={0};
	int t,ti;
	while(scanf("%d %d",&t,&ti)!=EOF){
		a[ti]=t;
	}
	for(int i=1;i<maxnum;i++){
		b[i-1] = a[i]*i;
	}
	
	int cnt=0;
	for(int i=0;i<maxnum;i++)
	{
		if(b[i]!=0) cnt++;
	}

	if(cnt==0) printf("0 0");
	else{
		for(int i=maxnum-1;i>=0;i--){
			if(b[i]!=0){
				printf("%d %d",b[i],i);
				cnt--;
				if(cnt) printf(" ");
			}
		}
	}

	return 0;
}

