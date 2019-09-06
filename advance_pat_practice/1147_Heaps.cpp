#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1010;
int n;
int le[maxn];
vector<int> tpath,postpath;
bool flag1,flag2;

void dfs(int root) {
	if(root>n) return;

	if(root*2>n) {
		tpath.push_back(le[root]);
		postpath.push_back(le[root]);
		for(int i=1; i<tpath.size(); i++) {
			if(tpath[i]>tpath[i-1]) flag1=false;
			if(tpath[i]<tpath[i-1]) flag2=false;
		}
		tpath.pop_back();
		return;
	}

	tpath.push_back(le[root]);
	dfs(root*2);
	if(root*2+1<=n) dfs(root*2+1);
	tpath.pop_back();
	postpath.push_back(le[root]);
}

int main(int argc, const char *argv[]) {
	int k;
	scanf("%d %d",&k,&n);

	for(int i=0; i<k; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d",&le[j]);
		}
		tpath.clear();
		postpath.clear();
		flag1=flag2=true;
		dfs(1);
		if(flag1) printf("Max Heap\n");
		else if(flag2) printf("Min Heap\n");
		else printf("Not Heap\n");
		for(int i=0; i<postpath.size(); i++) {
			if(i) printf(" ");
			printf("%d",postpath[i]);
		}
		printf("\n");
	}


	return 0;
}

