#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
using namespace std;

int main(int argc, const char *argv[])
{
	int a[1000]={0};
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s1.length();i++){
		a[s1[i]]=1;
		if(isalpha(s1[i])) a[tolower(s1[i])]=1;
	}
	for(int i=0;i<s2.length();i++){
		if(a['+']==1){
			if(a[s2[i]]==0&&!isupper(s2[i])) printf("%c",s2[i]);
		}else{
			if(a[s2[i]]==0) printf("%c",s2[i]);
		}
	}
	printf("\n");
	return 0;
}

