#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int s[1010];
vector<int> hobby[1010];
int findfather(int a){
	int temp=a;
	while(s[a]>0){
		a=s[a];
	}
	while(temp!=a){
		int t=s[temp];
		s[temp]=a;
		temp=t;
	}
	return a;
}
void u(int a,int b){
	int fa=findfather(a);
	int fb=findfather(b);
	if(fa!=fb){
		if(s[fa]>s[fb]){
			s[fb]+=s[fa];
			s[fa]=fb;
		}else{
			s[fa]+=s[fb];
			s[fb]=fa;
		}
	}
}
int main(int argc, const char *argv[])
{
	fill(s,s+1010,-1);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d:",&t);
		for(int j=0;j<t;j++){
			int s;
			scanf("%d",&s);
			hobby[s].push_back(i);
		}
	}

	for(int i=1;i<1010;i++){
		if(hobby[i].size()!=0){
			int root=hobby[i][0];
			for(int j=1;j<hobby[i].size();j++){
				u(root,hobby[i][j]);
			}
		}
	}
	int cnt=0,ans[1010];
	for(int i=1;i<=n;i++){
		if(s[i]<0) ans[cnt++]=s[i];
	}
	sort(ans,ans+cnt);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		if(i) printf(" ");
		printf("%d",-1*ans[i]);
	}
	return 0;
}

