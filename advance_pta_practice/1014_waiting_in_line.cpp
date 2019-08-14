#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int findmin(int a[],int n);
typedef struct person{
	int ti,id;
}per;
int main(int argc, const char *argv[])
{
	int n,m,k,q;
	per t[1010];
	int time[1010]={0};
	scanf("%d %d %d %d",&n,&m,&k,&q);
	for(int i=0;i<k;i++){
		scanf("%d",&t[i].ti);
		t[i].id=i+1;
	}
	vector<queue<per> > v(n);
	
	for(int i=0;i<k && i<n*m;i++){
		int qnum=i%n;
		v[qnum].push(t[i]);
	}
	
	int qnum;
	if(k>=n) qnum=n;
	else qnum=k;
	int sum[20]={0};
	for(int i=0;i<qnum;i++){
		sum[i]=v[i].front().ti;
	}
	int cnt=0;
	while(cnt<k){
		int minid=findmin(sum,qnum);
		time[v[minid].front().id]=sum[minid];
		v[minid].pop();
		if(n*m+cnt<k) v[minid].push(t[n*m+cnt]);
		if(v[minid].empty()) sum[minid]=99999999;
		cnt++;
		sum[minid]+=v[minid].front().ti;
//		cout<<sum[minid]<<endl;
	}
	for(int i=0;i<q;i++){
		int temp;
		scanf("%d",&temp);
		if(time[temp]-t[temp-1].ti<540){
			printf("%02d:%02d\n",time[temp]/60+8,time[temp]%60);
		}else printf("Sorry\n");
	}
	return 0;
}

int findmin(int a[],int n){
	int m=a[0],maxid=0;
	for(int i=0;i<n;i++){
		if(a[i]<m){
			m=a[i];
			maxid=i;
		}
	}
	return maxid;
}

