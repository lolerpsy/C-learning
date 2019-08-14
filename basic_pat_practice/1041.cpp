#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

typedef struct student{
	string id;
	int jn,kn;
}stu;

int main(int argc, char const *argv[])
{
	int n;
	stu s[1010];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s[i].id>>s[i].jn>>s[i].kn;
	}
	
	int m,t;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		cin>>t;
		for(int j=0;j<n;j++){
			if(t==s[j].jn)
			{
				cout<<s[j].id<<" "<<s[j].kn<<endl;
				break;
			}
		}
	}
	return 0;
}

