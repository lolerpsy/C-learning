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
			r=r + (char)((flag*10+s[i]-'0')/(n-'0')+'0');//���ǰһλ�������ϵ�ǰλ���ڳ�������ô����������������flag
			flag=(flag*10+s[i]-'0')%(n-'0');
		}else{
			r+="0";
			flag=s[i]-'0';//С�����λֱ�ӵ�������
		}
	}
	while(r[0]=='0'&&r.length()>1){//���ַ���ǰ��������ȥ��
		r=r.substr(1);
	}
	cout<<r<<" "<<flag<<endl;
	return 0;
}

