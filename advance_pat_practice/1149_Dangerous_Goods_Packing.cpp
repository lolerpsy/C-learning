#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000010;

int first[1010];
int second[1010];
bool hash1[maxn]={false};

int main(int argc, const char *argv[])
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		first[i]=a;
		second[i]=b;
	}
	
	for(int i=0;i<m;i++){
		fill(hash1,hash1+maxn,false);
		int k;
		scanf("%d",&k);
		bool flag=false;
		for(int j=0;j<k;j++){
			int t;
			scanf("%d",&t);
			hash1[t]=true;
			for(int v=0;v<1010;v++){
				if((t==first[v] && hash1[second[v]]==true) || (t==second[v] && hash1[first[v]]==true)){
					flag=true;
				}
			}
		}
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}

