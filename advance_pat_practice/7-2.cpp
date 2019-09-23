#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;
bool comp(string a,string b){
	return a.substr(6,8)<b.substr(6,8);
}

int main(int argc, const char *argv[])
{
	map<string,int> have;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		have[t]=1;
	}
	vector<string> tot;
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		string t;
		cin>>t;
		tot.push_back(t);
		if(have[t]==1) have[t]=2;
	}
	sort(tot.begin(),tot.end(),comp);
	bool a=false;
	string ans=tot[0];
	int cnt=0;
	for(int i=0;i<m;i++){
		if(have[tot[i]]==2){
			cnt++;
			if(!a){
				a=true;
				ans=tot[i];
			}
		}
	}
	if(a) printf("%d\n",cnt);
	cout<<ans;
	return 0;
}

