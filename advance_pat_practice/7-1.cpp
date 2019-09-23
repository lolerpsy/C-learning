#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

bool isprime(int a){
	if(a==1) return false;
	for(int i=2;i*i<=a;i++){
	if(a%i==0) return false;
	}
	return true;
}

bool sexy(int a){
	if(a<=6){
		if(isprime(a)&&isprime(a+6)) return true;
	}
	else{
		if((isprime(a) && isprime(a-6)) || (isprime(a) && isprime(a+6))) return true;
	}
	return false;
}

int main(){
	int n;
	scanf("%d",&n);
	if(sexy(n)){
		printf("Yes\n");
		if(isprime(n-6)) printf("%d",n-6);
		else printf("%d",n+6);
	}else{
		printf("No\n");
		for(int i=n;;i++){
			if(sexy(i)){
				printf("%d",i);
				break;
			}
		}
	}
	return 0;
}
