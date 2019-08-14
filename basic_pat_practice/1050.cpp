#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(int a,int b){
	return a>b;
}

int main(int argc, const char *argv[])
{
	int N;
	int m,n;
	int a[10005];
	scanf("%d",&N);
	for(int i=1;i*i<=N;i++){
		if(N%i==0) n=i;
	}
	m=N/n;
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+N,comp);
	
	vector<vector<int> > v(m,vector<int>(n));
	int levelmax=m/2+m%2;
	int cnt=0;
	for(int level=0;level<levelmax;level++){
		for(int i=level;i<=n-level-1&&cnt<=N-1;i++){
			v[level][i]=a[cnt++];
//			printf("%d %d\n",level,i);
		}
		for(int i=level+1;i<=m-level-2&&cnt<=N-1;i++){
			v[i][n-level-1]=a[cnt++];
//			printf("%d %d\n",i,n-level-1);
		}
		for(int i=n-level-1;i>=level&&cnt<=N-1;i--){
			v[m-level-1][i]=a[cnt++];
//			printf("%d %d\n",m-level,i);
		}
		for(int i=m-level-2;i>=level+1&&cnt<=N-1;i--){
			v[i][level]=a[cnt++];
//			printf("%d %d\n",level,i);
		}
	}
	printf("%d\n",cnt);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(j) printf(" ");
			printf("%d",v[i][j]);
		}
		printf("\n");
	}
	return 0;
}

