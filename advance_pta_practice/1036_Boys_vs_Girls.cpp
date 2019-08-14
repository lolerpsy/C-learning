#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct stdent{
	string name,id;
	int grade;
}stu;

bool comp(stu a,stu b){
	return a.grade>b.grade;
}

int main(int argc, char const *argv[])
{
	vector<stu> f,m;
	stu t;
	char gender;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>t.name>>gender>>t.id>>t.grade;
		if(gender=='F') f.push_back(t);
		else if(gender=='M') m.push_back(t);
	}
	if(f.size()) {
		sort(f.begin(),f.end(),comp);
		cout<<f[0].name<<" "<<f[0].id<<endl;
	}
	else cout<<"Absent\n";
	if(m.size()){
		sort(m.begin(),m.end(),comp);
		cout<<(m.end()-1)->name<<" "<<(m.end()-1)->id<<endl;
	}else cout<<"Absent\n";
	if(f.size()&&m.size()){
		cout<<f[0].grade-(m.end()-1)->grade<<endl;
	}else cout<<"NA\n";
	return 0;
}

