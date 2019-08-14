#include<iostream>
#include<cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	char t;
	int i=0;
	int hash[200]={0};
	while(scanf("%c",&t)!=EOF){
		if(t=='\n') continue;
		else {
			if(hash[t]==0){
				printf("%c",t);
				hash[t]=1;
			}
		}
	}
//	for(int j=0;j<i;j++){
//		if(s.find(st[j])!=s.end()){
//			auto it=s.find(st[j]);
//			printf("%c",st[j]);
//			s.erase(it);
//
//		}
//	}
//	printf("\n");
	return 0;
}

