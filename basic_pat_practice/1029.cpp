#include<cstdio>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(int argc,const char *argv[])
{
	int a[200]={0};
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s2.length();i++){
		a[s2[i]]=1;
	}
	for(int i=0;i<s1.length();i++){
		if(!a[s1[i]]){
			if(isalpha(s1[i])){
				printf("%c",toupper(s1[i]));
				a[toupper(s1[i])]=a[tolower(s1[i])]=1;
			}
			else printf("%c",s1[i]);
			a[s1[i]]=1;
		}
	}
	
	return 0;
}
