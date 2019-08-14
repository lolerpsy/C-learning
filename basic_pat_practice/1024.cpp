#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
using namespace std;

int main(int argc, const char *argv[])
{
	string s;
	cin>>s;
	int i=0;
	int cnt=0;
	
	char f=s[0];
	s=s.substr(1);
	while(s[i]!='E') i++;
	string s1=s.substr(0,i);

	int n=stoi(s.substr(i+1));
	cout<<s1<<"\n"<<n<<endl;
	if(f=='-') printf("%c",f);

	if(n<0){
		printf("0.");
		for(int i=0;i<(-1*n)-1;i++){
			printf("0");
		}
		for(int i=0;i<s1.length();i++){
			if(isdigit(s1[i])) printf("%c",s1[i]);
		}
	}else if(n>0){
		for(int i=0;cnt<n+1&&cnt<s1.length()-1;i++){
			if(s[i]!='.'){
				printf("%c",s[i]);
				cnt++;
			}
		}
		if(n+1<s1.length()-1){
			printf(".");
			for(int i=cnt+1;i<s1.length();i++){
				if(isdigit(s1[i])) printf("%c",s1[i]);
			}
		}
		else{
			for(int i=cnt;i<n+1;i++){
				printf("0");
			}
		}
	}else{
		cout<<s1;
	}

	return 0;
}

