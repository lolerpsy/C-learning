#include<iostream>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b);//求最大公约数
void printab(long long a,long long b);//输出分数
int main(int argc, const char *argv[])//这是一份丑陋的代码，重复代码很多，我对不起C++元编程的特性，但是这是一开始就想到的方法，就这样留着吧
{
	long long a1,a2,b1,b2;
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	long long r1,r2,r3;
	//�ӷ�
	r1=a1*b2+a2*b1;
	printab(a1,b1);
	printf(" + ");
	printab(a2,b2);
	printf(" = ");
	printab(r1,b1*b2);
	printf("\n");
	//����
	r2=a1*b2-a2*b1;
	printab(a1,b1);
	printf(" - ");
	printab(a2,b2);
	printf(" = ");
	printab(r2,b1*b2);
	printf("\n");
	//�˷�
	r3=a1*a2;
	printab(a1,b1);
	printf(" * ");
	printab(a2,b2);
	printf(" = ");
	printab(r3,b1*b2);
	printf("\n");
	//����
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

