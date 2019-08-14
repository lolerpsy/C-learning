#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int a1,a2,b1,b2;
	int cnt1=0,cnt2=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
		if(a2==(a1+b1)&&b2!=a2) cnt2++;
		else if(a2!=b2&&b2==(a1+b1)) cnt1++;
	}
	printf("%d %d\n",cnt1,cnt2);
	return 0;
}

