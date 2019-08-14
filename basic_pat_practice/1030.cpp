#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
int main(int argc, const char *argv[])
{
	int n;
	ll p,t;
	vector<ll> v;
	scanf("%d %lld",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%lld",&t);
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	int len=0;
	for(int i=0;i<n-len;i++){
		for(int j=i+len;j<n;j++){
			if(v[j]<=v[i]*p&&j-i+1>len){
				len=j-i+1;
			}else if(v[j]>v[i]*p) break;
		}
	}
	printf("%d",len);
	return 0;
}

