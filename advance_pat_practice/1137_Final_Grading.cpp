#include<iostream>
#include<cstdio>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct student{
	int online,mid,final,rfinal;
	string id;
};
bool comp(student a,student b){
	if(a.rfinal!=b.rfinal) return a.rfinal>b.rfinal;
	else return a.id<b.id;
}
int main(int argc, const char *argv[])
{
	student stu[10010];
	unordered_map<string,student> m;
	int p,m1,n;
	scanf("%d %d %d",&p,&m1,&n);
	for(int i=0;i<p;i++){
		string t;
		int on;
		cin>>t>>on;
		m[t].online=on;
		m[t].id=t;
		m[t].final=-1;
		m[t].mid=-1;
	}
	for(int i=0;i<m1;i++){
		string t;
		int mid;
		cin>>t>>mid;
		m[t].mid=mid;
		m[t].id=t;
	}
	for(int i=0;i<n;i++){
		string t;
		int final;
		cin>>t>>final;
		m[t].final=final;
		m[t].id=t;
	}
	int cnt=0;
	for(auto it:m){
		if(it.second.mid>it.second.final){
			double a=0.4*(double)it.second.mid+0.6*(double)it.second.final;
			int b1=a,b2=a+0.5;
			if(b2>b1) it.second.rfinal=b2;
			else it.second.rfinal=b1;
		}else it.second.rfinal=it.second.final;
		if(it.second.online>=200 && it.second.rfinal>=60){
			stu[cnt++]=it.second;
		}
//		cout<<cnt<<endl;
//		cout<<it.second.online<<" "<<it.second.rfinal<<endl;
	}
	sort(stu,stu+cnt,comp);
	for(int i=0;i<cnt;i++){
		cout<<stu[i].id<<" "<<stu[i].online<<" "<<stu[i].mid<<" "<<stu[i].final<<" "<<stu[i].rfinal<<endl;
	}
	return 0;
}

