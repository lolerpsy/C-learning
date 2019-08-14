#include<iostream>
#include<cstdio>
#include<cctype>
#include<map>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
	char s[1010];
	int i=0;
	while(scanf("%c",&s[i])!=EOF){
		i++;
	}
	map<char,int> m;
	for(int j=0;j<i;j++){
		if(isalpha(s[j])) m[tolower(s[j])]+=1;
	}
	int max1=0;
	char max2;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second>max1) {
			max2=it->first;
			max1=it->second;
		}
	}
	printf("%c %d\n",max2,m[max2]);

	return 0;
}

