#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
	string id,unlock_id,lock_id;
	int sh,sm,ss,eh,em,es,first=0,last=24*3600;
	int start,end;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>id;
		scanf("%d:%d:%d %d:%d:%d",&sh,&sm,&ss,&eh,&em,&es);
		start=sh*3600+sm*60+ss;
		end=eh*3600+em*60+es;
		if(start>=0 && end<24*3600 && start<end){
			if(start<last){
				unlock_id=id;
				last=start;
			}
			if(end>first){
				lock_id=id;
				first=end;
			}
		}
	}
	cout<<unlock_id<<" "<<lock_id<<endl;
	return 0;
}

