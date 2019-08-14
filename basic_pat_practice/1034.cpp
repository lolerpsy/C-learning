#include<iostream>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b);
void printab(long long a,long long b);
int main(int argc, const char *argv[])
{
	long long a1,a2,b1,b2;
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	long long r1,r2,r3;
	//加法
	r1=a1*b2+a2*b1;
	printab(a1,b1);
	printf(" + ");
	printab(a2,b2);
	printf(" = ");
	printab(r1,b1*b2);
	printf("\n");
	//减法
	r2=a1*b2-a2*b1;
	printab(a1,b1);
	printf(" - ");
	printab(a2,b2);
	printf(" = ");
	printab(r2,b1*b2);
	printf("\n");
	//乘法
	r3=a1*a2;
	printab(a1,b1);
	printf(" * ");
	printab(a2,b2);
	printf(" = ");
	printab(r3,b1*b2);
	printf("\n");
	//除法
	printab(a1,b1);
	printf(" / ");
	printab(a2,b2);
	printf(" = ");
	if(a2<0) {
		a2=-1*a2;
		b2=-1*b2;
	}
	if(a2!=0) printab(a1*b2,a2*b1);
	else printf("Inf");
	printf("\n");
	
	return 0;
}

long long gcd(long long a,long long b){
	long long temp;
	while(b!=0){
		temp=a;
		a=b;
		b=temp%b;
	}
	return a;
}
void printab(long long a,long long b){
	long long t=a;
	if(a==0) printf("0");
	else{
		if(a<0){
			printf("(-");
			a=-1*a;
		}
		long long g=gcd(a%b,b);
		if(a/b) printf("%lld",a/b);
		if(a/b && a%b) printf(" ");
		if(a%b) printf("%lld/%lld",a%b/g,b/g);
		if(t<0) printf(")");
	}
}
//12 102
//102 12
//12 6

