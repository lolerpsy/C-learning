#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct student{
	int id,dp,cp,tp;
}stu;

bool comp(stu a,stu b){
	if(a.tp!=b.tp) return a.tp>b.tp;
	else if(a.dp!=b.dp) return a.dp>b.dp;
	else return a.id<b.id;
}

int main(int argc, char const *argv[])
{
	vector<stu> s[4];
	stu t;
	int n,l,h;
	scanf("%d %d %d",&n,&l,&h);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&t.id,&t.dp,&t.cp);
		t.tp=t.dp+t.cp;
		if(t.dp>=h&&t.cp>=h) s[0].push_back(t);
		else if(t.dp>=h&&t.cp<h&&t.cp>=l) s[1].push_back(t);
		else if(t.dp<h&&t.dp>=l&&t.cp<h&&t.cp>=l&&t.dp>=t.cp) s[2].push_back(t);
		else if(t.dp>=l&&t.cp>=l) s[3].push_back(t);
	}
	int sum=0;
	for(int i=0;i<4;i++){
		sum+=s[i].size();
		sort(s[i].begin(),s[i].end(),comp);
	}
	printf("%d\n",sum);
	for(int i=0;i<4;i++){
		for(int j=0;j<s[i].size();j++){
			printf("%08d %d %d\n",s[i][j].id,s[i][j].dp,s[i][j].cp);
		}
	}

	return 0;
}

