#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc, const char *argv[])
{
	string s,s1,s2;
	char num[13]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
	
	cin>>s1>>s2;
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	if(s1.length()>s2.length()) s2.append(s1.length()-s2.length(),'0');
	else s1.append(s2.length()-s1.length(),'0');
	for(int i=1;i<=max(s1.length(),s2.length());i++){
		if(i%2==1){
			s+=num[(s1[i-1]-'0'+s2[i-1]-'0')%13];
		}else{
			if(s2[i-1]-s1[i-1]<0) s+=num[(s2[i-1]-s1[i-1]+10)];
			else s+=num[(s2[i-1]-s1[i-1])];
		}
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;

	return 0;
}
//
