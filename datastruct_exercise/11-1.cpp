#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;

int main(int argc, const char *argv[])
{
	map<string,int> m;
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<2*n;i++){
		string s;
		cin>>s;
		m[s]++;
	}
	int maxnum=0;
	string maxnumber="#";
	int cnt=0;
	for(auto it : m){
		if(it.second > maxnum){
			maxnum=it.second;
			maxnumber=it.first;
		}
	}
	for(auto it : m){
		if(it.second==maxnum){
			cnt++;
		}
	}
	
	cout<<maxnumber<<" "<<maxnum;
	if(cnt>1) cout<<" "<<cnt<<endl;

	return 0;
}

