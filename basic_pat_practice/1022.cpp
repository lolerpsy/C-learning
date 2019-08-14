#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int a,b,c;
	int d,sum=0;
	string r="";
	cin>>a>>b>>d;
	c=a+b;
	if(!c) r="0";
	while(c>0){
		sum=(c%d);
		r+=to_string(sum);
		c/=d;
	}
	reverse(r.begin(),r.end());
	cout<<r<<endl;
	
	return 0;
}

