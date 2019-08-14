#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, b;
	scanf("%d %d", &n, &b);
	int a[100]={0};//肯定不超过100位数，可以更小，懒得算了
	int index=0;
	while(n!=0){ //进制转换的常用模板
		a[index++]=n%b;
		n/=b;
	}
	bool isp=true;
	for(int i=0;i<index/2;i++){ //回文数的判断
		if(a[i]!=a[index-i-1]){
			printf("No\n");
			isp=false;
			break;
		}
	}
	if(isp) printf("Yes\n");
	for(int i=index-1;i>=0;i--){ //倒序输出
		printf("%d",a[i]);
		if(i) printf(" ");
	}
	if(index==0) printf("0");
	return 0;
}
