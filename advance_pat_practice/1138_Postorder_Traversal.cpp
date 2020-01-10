#include<iostream>
#include<cstdio>
using namespace std;
int pre[50010],in[50010];
bool printed=false;
void creat(int prel,int prer,int inl,int inr){
	if(prel>prer || printed){
		return;
	}
	int i=inl;
	while(i<=inr&&in[i]!=pre[prel]) i++;
	creat(prel+1,prel+(i-inl),inl,i-1);
	creat(prel+i-inl+1,prer,i+1,inr);
	if(!printed){
		printf("%d",pre[prel]);
		printed=true;
	}
}
int main(int argc, const char *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&pre[i]);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	creat(0,n-1,0,n-1);
	return 0;
}

