#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long ll;
int todigit(const char a);
ll to_decimal(string s,const int radix);
int main(){
	string s1,s2;
	int tag,radix;
	cin>>s1>>s2>>tag>>radix;
	
	if(tag==2) swap(s1,s2);
	
	int minradix=todigit(s2[0])+1;
	for(int i=0;i<s2.length();i++){
		if(todigit(s2[i])+1>minradix) minradix=todigit(s2[i])+1;
	}
	
	ll n1=to_decimal(s1,radix);
	ll low=minradix,high=max(low,n1),mid;
	while(low<=high){
		mid=(low+high)/2;
		ll n2=to_decimal(s2,mid);
		if(n2>n1 || n2<0) high=mid-1;
		else if(n2==n1) break;
		else low=mid+1;
	}
	if(low<=high) cout<<mid<<endl;
	else cout<<"Impossible\n";
	
	return 0;
}

int todigit(const char a){
	int ret=-1;
	if(isdigit(a)) ret=a-'0';
	else if(islower(a)) ret=a-'a'+10;
	return ret;
}

ll to_decimal(string s, const int radix){
	ll num=0;
	for(int i=0;i<s.length();i++){
		num=num*radix+todigit(s[i]);
		if(num<0) break;
	}
	return num;
}
