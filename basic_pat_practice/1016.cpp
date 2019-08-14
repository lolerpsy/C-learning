#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	string a,b;
	char m,n;
	long long sum1=0,sum2=0;
	cin>>a>>m>>b>>n;
	for(int i=0;i<a.length();i++){
		if(a[i]==m)
		sum1=sum1*10+m-'0';
	}
	for(int i=0;i<b.length();i++){
		if(b[i]==n)
		sum2=sum2*10+n-'0';
	}
	cout<<sum1+sum2<<endl;
	return 0;
}

