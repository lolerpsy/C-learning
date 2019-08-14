#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(int argc, const char *argv[])
{
	string t;
	string g[14]= {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	string s[13]= {"####","tam", "hel","maa","huh", "tou","kes","hei","elo","syy","lok","mer","jou"};
	int n,a,b,c;
	scanf("%d",&n);
	getchar();
	for(int j=0; j<n; j++) {
		b=0;
		c=0;
		getline(cin,t);
		if(isdigit(t[0])) {
			a=stoi(t);
			if(a>=13) {
				cout<<s[a/13];
				if(a>13&&a%13) cout<<" "<<g[a%13];
				cout<<"\n";
			} else {
				cout<<g[a]<<endl;
			}
		} else if(isalpha(t[0])) {
			if(t.length()<=4) {
				for(int i=0; i<13; i++) {
					if(t==g[i]) {
						b=i;
					}else if(t==s[i]) c=i;
				}
			} else {
				for(int i=0; i<13; i++) {
					if(t.substr(0,3)==s[i]) c=i;
					if(t.substr(4)==g[i]) b=i;
				}
			}
			cout<<b+c*13<<endl;
		}
	}

	return 0;
}//13,26...这些能被13整除的数不用输出第二位。。。。。

