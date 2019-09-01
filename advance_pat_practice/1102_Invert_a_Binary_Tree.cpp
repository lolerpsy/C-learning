#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct node{
    int l,r;
}tree[11];

void level(int root){//层次遍历
    queue<int> q;
    printf("%d",root);
    q.push(root);
    while ( !q.empty() ){
        int t = q.front();
        q.pop();
        if ( tree[t].r != -1 ){//反转二叉树，先右后左
            printf(" %d", tree[t].r);
            q.push(tree[t].r);
        }
        if (tree[t].l != -1){
            printf(" %d", tree[t].l);
            q.push(tree[t].l);
        }
    }
    printf("\n");
}

int cnt=0;//计数器
void in(int root){//中序遍历
    if(root==-1) return;
    in(tree[root].r);
    if(cnt) printf(" ");
    printf("%d",root);
    cnt++;
    in(tree[root].l);
}

int main(){
    int n;
    scanf("%d",&n);
    int check[11]={0};
    for(int i=0;i<n;i++){
        char a,b;
        cin>>a>>b;
        if(a=='-') tree[i].l=-1;
        else {
            tree[i].l=a-'0';
            check[a-'0']=1;
        }
        if(b=='-') tree[i].r=-1;
        else{
            tree[i].r=b-'0';
            check[b-'0']=1;
        }
    }

    int root=0;
    while(check[root]!=0 && root<n) root++;

    level(root);
    in(root);

    return 0;
}
