#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
using namespace std;

int main(int argc, const char *argv[])
{
//tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou
	string g[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	string s[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	int n;
	cin>>n;
	getchar();
	string t;
	for(int i=0;i<n;i++){
		getline(cin,t);
		if(isdigit(t[0])){
			int a=stoi(t);
			if(a<13) cout<<g[a];
			else{
				cout<<s[a/13];
				if(a%13) cout<<" "<<g[a%13];
			}
			cout<<"\n";
		}else{
			int b=0,c=0;
			if(t.length()<=4){
				for(int i=0;i<13;i++){
					if(t==g[i]) c=i;
					if(t==s[i]) b=i;
				}
			}else{
				for(int i=0;i<13;i++){
					if(t.substr(0,3)==s[i]) b=i;
					if(t.substr(4)==g[i]) c=i;
				}
			}
			cout<<b*13+c<<endl;
		}
	}

	return 0;
}

