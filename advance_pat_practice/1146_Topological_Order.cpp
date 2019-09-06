#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1010;
vector<int> v[maxn];

int main(int argc, const char *argv[])
{
	int n,m;
	scanf("%d %d",&n,&m);

	vector<int> inde(n+1,0);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		inde[b]++;
	}

	int k;
	scanf("%d",&k);
	vector<int> ans;

	for(int j=0;j<k;j++) {
		bool flag=true;
		vector<int> in=inde;

		for(int i=0;i<n;i++){
			int t;
			scanf("%d",&t);
			if(!flag) continue;
			if(in[t]!=0) flag=false;
			for(int x:v[t]){
				in[x]--;
			}
		}

		if(!flag){
			ans.push_back(j);
		}
	}

	for(int i=0;i<ans.size() ;i++){
		if(i) printf(" ");
			printf("%d",ans[i]);
	}
	return 0;
}

