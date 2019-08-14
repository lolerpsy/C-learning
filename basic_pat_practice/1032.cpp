#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010];
int main(int argc, char const *argv[])
{
	int n;
	int school,point;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&school,&point);
		a[school-1]+=point;
	}
	int maxpoint=0,maxschool;
	for(int i=0;i<n;i++){
		if(a[i]>maxpoint){
			maxpoint =a[i];
			maxschool=i;
		}
	}
	printf("%d %d",maxschool+1,maxpoint);
	return 0;
}

