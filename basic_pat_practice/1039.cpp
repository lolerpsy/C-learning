#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<map>
using namespace std;

int main(int argc, const char *argv[])
{
	string s1,s2;
	cin>>s1>>s2;
	map<char,int> m1,m2;
	set<char> se2;
	for(int i=0;i<s1.length();i++){
		m1[s1[i]]++;
	}
	for(int i=0;i<s2.length();i++){
		m2[s2[i]]++;
		se2.insert(s2[i]);
	}
	bool equal=true;
	int less=0;
	for(auto it=se2.begin();it!=se2.end();it++){
		if(m1[*it]<m2[*it]){
			equal=false;
			less+=m2[*it]-m1[*it];
		}
	}
	if(equal) cout<<"Yes "<<(int)s1.length()-s2.length()<<endl;
	else cout<<"No "<<less<<endl;
	
	return 0;
}

