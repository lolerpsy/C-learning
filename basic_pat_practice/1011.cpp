#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	long long a,b,c;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		printf("Case #%d ",i);
		if(a+b>c) printf("true");
		else printf("false");
	}
	return 0;
}
