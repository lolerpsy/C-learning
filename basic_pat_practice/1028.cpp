#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

bool less1(int a[],int b[],int n){
	bool ret=false;
	for(int i=0;i<n;i++){
		if(a[i]<b[i]){
			ret=true;
			break;
		}
		else if(a[i]>b[i]){
			ret=false;
			break;
		}
		else continue;
	}
	return ret;
}
bool more1(int a[],int b[],int n){
	bool ret=false;
	for(int i=0;i<n;i++){
		if(a[i]>b[i]){
			ret=true;
			break;
		}else if(a[i]<b[i]){
			ret=false;
			break;
		}else continue;
	}
	return ret;
}
int main(){
	string name,maxname,minname;
	int birth[3],least[3]={1814,9,06},most[3]={2014,9,06};
	int n,cnt=0;
	int a[3]={1814,9,06},b[3]={2014,9,06};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>name;
		scanf("%d/%d/%d",&birth[0],&birth[1],&birth[2]);
		if(!less1(birth,least,3) && !more1(birth,most,3)){
			cnt++;
			if(more1(birth,a,3)){
				maxname=name;
				for(int i=0;i<3;i++){
					a[i]=birth[i];
				}
			}
			if(less1(birth,b,3)){
				minname=name;
				for(int i=0;i<3;i++){
					b[i]=birth[i];
				}
			}
		}
	}

	if(cnt) printf("%d %s %s\n",cnt,minname.c_str(),maxname.c_str());
	else printf("0");
	
	return 0;
}
