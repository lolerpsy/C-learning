#include<iostream>
#include<cstdio>
#include<cctype>
#include<queue>
using namespace std;
struct node {
	int l,r;
};
node bit[25];
int cnt=0,ans=0;
void letravel(int root) {
	int lastnode=0;
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int t=q.front();
		q.pop();
		if(t!=-1) {
			lastnode=t;
			cnt++;
		} else {
			ans=lastnode;
			return;
		}
		q.push(bit[t].l);
		q.push(bit[t].r);
	}
}
int main(int argc, const char *argv[]) {
	int n,root=-1,check[25]= {0};
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		string a,b;
		cin>>a>>b;
		if(a!="-") {
			bit[i].l=stoi(a);
			check[stoi(a)]=1;
		} else bit[i].l=-1;
		if(b!="-") {
			bit[i].r=stoi(b);
			check[stoi(b)]=1;
		} else bit[i].r=-1;
	}
	for(int i=0; i<n; i++) {
		if(check[i]==0) {
			root=i;
			break;
		}
	}
	letravel(root);
	if(cnt==n) printf("YES %d\n",ans);
	else printf("NO %d\n",root);
	return 0;
}

