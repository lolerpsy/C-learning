#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int main(int argc, const char *argv[])
{
	int n,m;
	int have[100]={0};
	int a[100][100];
	fill(a[0],a[0]+10000,0);
	int t,k[100];
	queue<int> s;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int temp;
		scanf("%d %d",&t,&temp);
		have[t]=1;
		k[t]=temp;
		for(int j=0;j<k[t];j++){
			scanf("%d",&a[t][j]);
		}
	}
	
	if(n==1) printf("1");
	else{
		int sum=0;
		s.push(1);
		int lnum=1,cnt=0;
		if(n-m) printf("0");
		while(sum<n-m){
			int leaves=0,xnum=0;
			for(int i=0;i<lnum;i++){
				int t=s.front();
				s.pop();
				for(int j=0;j<k[t];j++){
					if(have[a[t][j]]==1){
						xnum++;
						s.push(a[t][j]);
					}
				}
				leaves+=k[t]-xnum;
			}
			printf(" %d",leaves);
			cnt++;
			lnum=xnum;
			sum+=leaves;
		}
	}

	return 0;
}

