#include<iostream>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
	ll a,b,c;
	int n;
	ll ret;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		ret=a+b;
		printf("Case #%d: ",i);
		if(a>0&&b>0&&ret<0) printf("true\n");
		else if(a<0&&b<0&&ret>0) printf("false\n");
		else if(a+b>c) printf("true\n");
		else printf("false\n");
	}

	return 0;
}

