#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	const int max=150000;
	int prime[max];
	int start,end;
	scanf("%d %d",&start,&end);
	fill(prime,prime+max,1);
	for(int i=2;i*i<max;i++){
		if(prime[i]){
			for(int j=2;i*j<max;j++)
				prime[i*j]=0;
		}
	}
	int cnt=0,cnt1=0;
	for(int i=2;i<max;i++){
		if(prime[i]){
			cnt++;
			if(cnt>=start){
				cnt1++;
				printf("%6d",i);
				if(cnt1%10 && cnt!=end)	printf(" ");
				else if(cnt1%10==0) printf("\n");
			}
		}
		if(cnt==end) break;
	}
	return 0;
}

