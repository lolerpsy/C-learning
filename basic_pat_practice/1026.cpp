#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int start,end;
	int st;
	int h,m,s;
	cin>>start>>end;
	st=end-start;
	if(st%100>=50) st=st/100+1;
	else st=st/100;
	h=st/3600;
	m=st%3600/60;
	s=st%60;
	printf("%2d:%2d:%2d\n",h,m,s);
	return 0;
}

