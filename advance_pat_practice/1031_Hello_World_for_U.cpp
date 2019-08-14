#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int N=s.length();
	int k=0,n1,n2;
	for( n2=3;n2<=N;n2++){
		n1=(N+2-n2)/2;
		if(n1<=n2&&n1>k){
			k=n1;
		}
	}
	n2=N+2-2*k;
	for(int i=0;i<k-1;i++){
		printf("%c",s[i]);
		for(int j=0;j<n2-2;j++){
			printf(" ");
		}
		printf("%c\n",s[N-1-i]);
	}
	printf("%s",s.substr(k-1,n2).c_str());
	return 0;
}

