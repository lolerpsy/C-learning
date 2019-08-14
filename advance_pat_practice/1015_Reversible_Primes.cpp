#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

bool isprime(int a){
	bool ret=true;
	if(a==1) return false;
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			ret=false;
			break;
		}
	}
	return ret;
}

bool reversible(int a,int radix){
	bool p=isprime(a);
	string s="";
	while(a>0){
		s+=to_string(a%radix);
		a/=radix;
	}
	int newa=0;
	for(int i=0;i<s.length();i++){
		newa=newa*radix+s[i]-'0';
	}
	bool rp=isprime(newa);
	return p&&rp;
}

int main(int argc, const char *argv[])
{
	int i=0,t;
	while(scanf("%d",&t)){
		int a,b;
		if(t<0) break;
		if(i%2==0) a=t;
		else{
			b=t;
			if(reversible(a,b)) printf("Yes\n");
			else printf("No\n");
		}
		i++;
	}

	return 0;
}

