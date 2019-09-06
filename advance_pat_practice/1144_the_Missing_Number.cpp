#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
typedef long long ll;

int main(int argc, const char *argv[])
{
	int n;
	scanf("%d",&n);
	unordered_map<int,bool> have;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(t>0) have[t]=true;
	}
	int i=1;
	while(1){
		if(!have[i]){
			printf("%d",i);
			break;
		}
		i++;
	}

	return 0;
}

