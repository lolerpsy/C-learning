#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
struct node{
    int data,h,size;
    node *l,*r;
};
int geth(node *root){
    if(!root) return 0;
    else return root->h;
}
int getsize(node *root){
    if(!root) return 0;
    else return root->size;
}
void updateh(node *root){
    if(!root) return;
    else root->h=max(geth(root->l),geth(root->r))+1;
}
void updates(node *root){
    if(!root) return;
    else root->size=getsize(root->l)+getsize(root->r)+1;
}
void R(node *&root){
    node *temp=root->l;
    root->l=temp->r;
    temp->r=root;
    updateh(root);
    updates(root);
    updates(temp);
    updateh(temp);
    root=temp;
}
void L(node *&root){
    node *temp=root->r;
    root->r=temp->l;
    temp->l=root;
    updates(root);
    updates(temp);
    updateh(root);
    updateh(temp);
    root=temp;
}
void insert(node *&root,int data){
    if(!root){
        root=new node;
        root->h=1;
        root->data=data;
        root->size=1;
        root->l=root->r=NULL;
        return;
    }
    if(data>=root->data){
        insert(root->r,data);
        updateh(root);
        updates(root);
        if(geth(root->r)-geth(root->l)>=2){
            if(geth(root->r->r)-geth(root->r->l)>=1){
                L(root);
            }else{
                R(root->r);
                L(root);
            }
        }
    }else{
        insert(root->l,data);
        updateh(root);
        updates(root);
        if(geth(root->l)-geth(root->r)>=2){
            if(geth(root->l->l)-geth(root->l->r)>=1){
                R(root);
            }else{
                L(root->l);
                R(root);
            }
        }
    }
}
int cnt=0,flag=1;
void leveltravel(node *root){
    queue<node *>q;
    q.push(root);
    while(!q.empty()){
        node *t=q.front();
        q.pop();
        if(cnt) printf(" ");
        printf("%d",t->data);
        cnt++;
        int lsize=getsize(t->l);
        int rsize=getsize(t->r);
        int lh=geth(t->l);
        int rh=geth(t->r);
        if(lh==rh && lsize!=(int)pow(2,lh)-1) flag=0;
        if(lh<rh || lh-rh>=2) flag=0;
        if(lh==rh+1 &&rsize!=int(pow(2,rh)-1)) flag=0;
        if(t->l) q.push(t->l);
        if(t->r) q.push(t->r);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    node *root=NULL;
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        insert(root,t);
    }
    leveltravel(root);
    printf("\n");
    printf("%s\n",flag ? "YES":"NO");
    return 0;
}
