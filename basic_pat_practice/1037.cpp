#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int g1,s1,k1,g2,s2,k2;
	int t,t1,t2;
	scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
	t1=k1+s1*29+g1*17*29;
	t2=k2+s2*29+g2*17*29;
	t=t2-t1;
	if(t<0){
		t=-t;
		printf("-");
	}
	printf("%d.%d.%d\n",t/(17*29),t%(17*29)/29,t%29);
	return 0;
}

