#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s,r="";
	char n;
	cin>>s>>n;
	int flag=0;
	for(int i=0;i<s.length();i++){
		if(flag*10+s[i]>=n){
			r=r + (char)((flag*10+s[i]-'0')/(n-'0')+'0');//如果前一位余数加上当前位大于除数，那么做除法，余数存入flag
			flag=(flag*10+s[i]-'0')%(n-'0');
		}else{
			r+="0";
			flag=s[i]-'0';//小于则该位直接当作余数
		}
	}
	while(r[0]=='0'&&r.length()>1){//把字符串前面多余的零去掉
		r=r.substr(1);
	}
	cout<<r<<" "<<flag<<endl;
	return 0;
}

