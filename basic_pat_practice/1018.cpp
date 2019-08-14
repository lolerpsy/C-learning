#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	char y1,y2;
	int w1=0,e1=0,l1=0;
	map<char,int> m1,m2;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>y1>>y2;
		if(y1=='C'){
			if(y2=='J'){
				w1++;
				m1['C']+=1;
			}else if(y2=='C'){
				e1++;
			}else{
				l1++;
				m2['B']+=1;
			}
		}
		else if(y1=='J'){
			if(y2=='J'){
				e1++;
			}else if(y2=='C'){
				m2['C']++;
				l1++;
			}else{
				w1++;
				m1['J']++;
			}
		}else{
			if(y2=='J'){
				l1++;
				m2['J']++;
			}else if(y2=='C'){
				w1++;
				m1['B']++;
			}else{
				e1++;
			}
		}
	}

	printf("%d %d %d\n",w1,e1,l1);
	printf("%d %d %d\n",l1,e1,w1);
	char max1='B',max2='B';
	int max=0;
	for(auto it=m1.begin();it!=m1.end();it++){
		if(it->second>max) {
			max1=it->first;
			max=it->second;
		}
	}
	max=0;
	for(auto it=m2.begin();it!=m2.end();it++){
		if(it->second>max){
			max2=it->first;
			max=it->second;
		}
	}
	printf("%c %c\n",max1,max2);

	return 0;
}

