#include<iostream>
#include<cctype>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int min1(unsigned a,unsigned b){
	return a<b ? a:b;
}

int main(int argc, char const *argv[])
{
	string s[4];
	for(int i=0;i<4;i++){
		cin>>s[i];
	}
	map<char,int> m;
	char d,h;
	int flag=0;
	for(unsigned i=0;i<(min1(s[0].length(),s[1].length()));i++){
		if(flag==0&&s[0][i]==s[1][i] && s[0][i]>='A'&&s[0][i]<='G'){
			flag=1;
			d=s[0][i];
		}
		else if(flag==1&&s[0][i]==s[1][i]&&((s[0][i]<='N'&&s[0][i]>='A')||(s[0][i]>='0'&&s[0][i]<='9'))){
			h=s[0][i];
			break;
		}
	}
	int cnt=0;
	for(unsigned i=0;i<min1(s[2].length(),s[3].length());i++){
		if(s[2][i]==s[3][i] && isalpha(s[2][i])){
			break;
		}
		cnt++;
	}

	string day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN",};
	int t=0;
	for(char i='0';i<='9';i++){
		m[i]=t;
		t++;
	}
	for(char i='A';i<='N';i++){
		m[i]=t;
		t++;
	}

 	printf("%s %02d:%02d\n",day[d-'A'].c_str(),m[h],cnt);
	
	return 0;
}

