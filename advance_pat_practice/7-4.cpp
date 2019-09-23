#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int data,l,r;
};
node tree[35];
int post[35],in[35];
void create(int start,int end,int postroot){
	if(start>end) return;
	int i=start;
	while(i<=end && in[i]!=post[postroot]) i++;
	tree[postroot].data=post[postroot];
	tree[postroot].l=max(postroot-(end-i)-1,-1);
	tree[postroot].r=max(postroot-1,-1);
	create(start,i-1,postroot-(end-i)-1);
	create(i+1,end,postroot-1);
}

int main(int argc, const char *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	int root=post[n-1];
	create(0,n-1,n-1);
	int m;
	scanf("%d",&m);
	getchar();
	for(int i=0;i<m;i++){
		string t;
		getline(cin,t);
		if(t[t.length()-1]=='t'){
			int x;
			sscanf(t.c_str(),"%d is the root",&x);
			if(x==root) printf("Yes\n");
			else printf("No\n");
		}else if(t[t.length()-1]=='s'){
			int a,b;
			sscanf(t.c_str(),"%d and %d are siblings",&a,&b);
			int i;
			for(i=0;i<n;i++){
				if(tree[i].l!=-1&&tree[i].r!=-1){
					if((tree[tree[i].l].data=a&&tree[tree[i].r].data==b)||(tree[tree[i].r].data==a&&tree[tree[i].l].data==b))
					{
						printf("Yes\n");
						break;
					}
				}
			}
			if(i==n) printf("No\n");
		}else if(t[t.length() -1]=='l'){
			int a,b;
			sscanf(t.c_str(),"%d and %d are on the same level",&a,&b);
			queue<int> q,le;
			int lea=-1,leb=-2;
			q.push(n-1);
			le.push(0);
			while(!q.empty()){
				int v=q.front(),tle=le.front();
				le.pop();
				q.pop();
				if(tree[v].data==a) lea=tle;
				if(tree[v].data==b) leb=tle;
				if(tree[v].l!=-1) q.push(tree[v].l);
				if(tree[v].r!=-1) q.push(tree[v].r);
			}
			if(lea==leb) printf("Yes\n");
			else printf("No\n");
		}else if(t[t.length() -1]=='e'){
			bool flag=true;
			queue<int> q;
			q.push(n-1);
			while(!q.empty()){
				int v=q.front();
				q.pop();
				if((tree[v].l==-1 && tree[v].r!=-1) || (tree[v].r==-1 && tree[v].l!=-1)){
					flag=false;
					break;
				}
				if(tree[v].l!=-1) q.push(tree[v].l);
				if(tree[v].r!=-1) q.push(tree[v].r);
			}
			if(flag) printf("Yes\n");
			else printf("No\n");
		}else{
			int a,b;
			char s[10];
			sscanf(t.c_str() ,"%d is the %s child of %d",&a,s,&b);
			if(s[0]=='l'){
				int i;
				for(i=0;i<n;i++){
					if(tree[i].data==b && tree[tree[i].l].data==a)
					{
						printf("Yes\n");
						break;
					}
				}
				if(i==n) printf("No\n");
			}else if(s[0]=='r'){
				int i;
				for(i=0;i<n;i++){
					if(tree[i].data==b && tree[tree[i].r].data==a)
					{
						printf("Yes\n");
						break;
					}
				}
				if(i==n) printf("No\n");
			}else if(s[0]=='p'){
				int i;
				for(i=0;i<n;i++){
					if((tree[i].data==a && tree[tree[i].l].data==b) ||(tree[i].data==a&&tree[tree[i].r].data==b))
					{
						printf("Yes\n");
						break;
					}
				}
				if(i==n) printf("No\n");
			}
		}
	}

	return 0;
}

