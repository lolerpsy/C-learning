#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int data,le;
	struct node *l,*r;
};

void insert(struct node* &root,int v){
	if(!root){
		root=new node;
		root->data=v;
		root->l=NULL;
		root->r=NULL;
		return;
	}
	if(v<=root->data) insert(root->l,v);
	else insert(root->r,v);
}
vector<int> level[1010];
int maxlevel=0;
void letravel(node* root){
	queue<node*> q;
	root->le=0;
	q.push(root);
	while(!q.empty()){
		node* t=q.front();
		q.pop();
		if(t->le > maxlevel) maxlevel=t->le;
		level[t->le].push_back(t->data);
		if(t->l){
			t->l->le=t->le+1;
			q.push(t->l);
		}
		if(t->r){
			t->r->le=t->le+1;
			q.push(t->r);
		}
	}
}
int main(int argc, const char *argv[])
{
	int n;
	scanf("%d",&n);
	struct node *root=NULL;
	for(int i=0;i<n;i++){
		int v;
		scanf("%d",&v);
		insert(root,v);
	}
	letravel(root);
	
	printf("%d + %d = %d",level[maxlevel].size(),level[maxlevel-1].size(),level[maxlevel].size()+level[maxlevel-1].size());

	return 0;
}

