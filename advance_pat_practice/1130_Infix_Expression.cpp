#include <cstdio>
#include<iostream>
#include<string>
using namespace std;
struct node{
    string data;
    int left,right;
};
node tree[25];
int n;
void printtree(int v,int root){
    if(v==-1) return;
    if(v!=root && (tree[v].left!=-1||tree[v].right!=-1)) printf("(");
    printtree(tree[v].left,root);
    cout<<tree[v].data;
    printtree(tree[v].right,root);
    if(v!=root && (tree[v].left!=-1||tree[v].right!=-1)) printf(")");
}
int main(){
    scanf("%d",&n);
    int check[25]={0};
    for(int i=1;i<=n;i++){
        string t;
        int a,b;
        cin>>t>>a>>b;
        tree[i].data=t;
        tree[i].left=a;
        tree[i].right=b;
        if(a!=-1) check[a]=1;
        if(b!=-1) check[b]=1;
    }
    int root=0;
    for(int i=1;i<=n;i++){
        if(check[i]==0){
            root=i;
            break;
        }
    }
    printtree(root,root);
    return 0;
}
