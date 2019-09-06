#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

bool isprime(int a){
	if(a==1) return false;
	for(int i=2;i*i<=a;i++){
		if(a%i==0) return false;
	}
	return true;
}

int main(int argc, const char *argv[])
{
	int msize,n,m;
	scanf("%d %d %d",&msize,&n,&m);
	while(!isprime(msize)) msize++;
	
	int myhash[100010]={0};
	vector<int> hashtable(msize,0);
	
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		int d=0;
		while(hashtable[(t+d*d)%msize]!=0 && d < msize){
			d++;
		}
		if(d < msize){
			hashtable[(t+d*d)%msize]=t;
			myhash[t]=d+1;
		}
		else if(d == msize) printf("%d cannot be inserted.\n",t);
	}
	
	int ans=0;
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		if(myhash[t]!=0) ans+=myhash[t];
		else{
			int d=0;
			while(hashtable[(t+d*d)%msize]!=0 && d < msize){
				d++;
			}
			ans+=(d+1);
		}
	}
	
	printf("%.1lf",(double)ans/m);

	return 0;
}

