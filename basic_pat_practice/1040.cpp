#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, const char *argv[])
{
	const int N=1000000007;
	int p[100000]={0},t[100000]={0};
	int pn=0,an=0,tn=0;
	char temp;
	while(scanf("%c",&temp)!=EOF){
		if(temp=='A'){
			p[an]=pn;
			t[an]=tn;
			an++;
		}else if(temp=='P'){
			pn++;
		}else if(temp=='T'){
			tn++;
		}
	}
	for(int i=0;i<an;i++){
		t[i]=tn-t[i];
	}
	int sum=0;
	for(int i=0;i<an;i++){
		sum=(sum+(p[i]%N)*(t[i]%N)%N)%N;
	}
	printf("%d\n",sum%N);
	return 0;
}

