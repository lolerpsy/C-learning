#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int n,cnt=0,origin[110],level[110];

struct node{
  int data;
  int l,r;
}tree[110];
//二叉搜索树的中序遍历就是从小到大的排序，
//因此可以先对原始序列进行从小到大排序，再用中序遍历给每个节点赋值
void in(int root){//中序遍历
  if (root == -1) return;
  in(tree[root].l);
  tree[root].data = origin[cnt++];
  in(tree[root].r);
}

int cnt1=0;
void le(int root){//层次遍历
  queue <int> q;
  level[cnt1++] = tree[root].data;
  q.push(root);
  while ( !q.empty() ){
    int t = q.front();
    q.pop();
    if ( tree[t].l != -1 ) {
      level[cnt1++]=tree[tree[t].l].data;
      q.push(tree[t].l);
    }
    if ( tree[t].r!=-1 ) {
      level[cnt1++]=tree[tree[t].r].data;
      q.push(tree[t].r);
    }
  }
}

int main(){
  scanf("%d",&n);
  for (int i=0; i < n; i++) {
    scanf("%d %d", &tree[i].l, &tree[i].r);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &origin[i]);
  }
  sort(origin,origin+n,less<int>());//排序
  in(0);
  le(0);
  for ( int i = 0; i < n ; i++ ) {//输出
    if (i!=0) printf(" ");
    printf("%d", level[i]);
  }
  return 0;
}
