#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string add(string a,string b){
	string s(a);
	int flag=0;
	for(int i=a.length()-1;i>=0;i--){
		s[i]=a[i]+b[i]-'0'+flag;
		if(s[i]>'9'){
			flag=1;
			s[i]-=10;
		}else{
			flag=0;
		}
	}
	if(flag) s='1'+s;
	return s;
}
bool palin(string a){
	string s=a;
	reverse(s.begin(),s.end());
	return a==s;
}
int main(int argc, const char *argv[])
{
	string s1,s2;
	cin>>s1;
	bool flag=false;
	for(int i=0;i<10;i++){
		if(palin(s1)) {
			printf("%s is a palindromic number.\n",s1.c_str());
			flag=true;
			break;
		}
		s2=s1;
		reverse(s2.begin(),s2.end());
		string s=add(s1,s2);
		cout<<s1<<" + "<<s2<<" = "<<s<<endl;
		s1=s;
	}
	if(!flag) printf("Not found in 10 iterations.\n");
	return 0;
}

