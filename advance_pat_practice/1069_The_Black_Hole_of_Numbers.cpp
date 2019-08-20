#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

bool comp1(char a,char b){
	return a>b;
}

bool comp2(char a,char b){
	return a<b;
}//sort默认的compare函数就是这个，可以不用写

int main(int argc, char const *argv[])
{
	int n;
	string t,t1,t2;
	scanf("%d",&n);

	do{
		t=to_string(n);
		while(t.length()!=4) t="0"+t;//要是对t.length()作加减一定记住其是unsigned类型，小于0会溢出

		if(t[0]==t[1]&&t[1]==t[2]&&t[2]==t[3]){
			printf("%s - %s = 0000\n",t.c_str(),t.c_str());
			break;
		}

		t1=t2=t;
		sort(t1.begin(),t1.end(),comp1);
		sort(t2.begin(),t2.end(),comp2);
		n=stoi(t1)-stoi(t2);
		printf("%s - %s = %04d\n",t1.c_str(),t2.c_str(),n);
	}while(n!=6174);

	return 0;
}

