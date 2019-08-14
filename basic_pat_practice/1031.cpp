#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(int argc, const char *argv[])
{
	int n;
	scanf("%d",&n);
	int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char terrify[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	string t;
	int sum=0;
	int cnt=0;
	for(int i=0;i<n;i++){
		sum=0;
		cin>>t;
		for(int j=0;j<17;j++){
			sum+=((t[j]-'0')*weight[j]);
		}
		if(terrify[sum%11]!=t[17]) {
			cout<<t<<endl;
			cnt++;
		}
	}
	if(!cnt) printf("All passed\n");
	return 0;
}

