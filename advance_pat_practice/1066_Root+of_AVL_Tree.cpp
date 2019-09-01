#include <algorithm>
#include <cstdio>

using namespace std;

struct node { // AVL树节点结构体，增加了高度计数器
  int data;
  int h;
  node *left, *right;
};

int getheight(node *root) {
  if (!root)
    return 0; //注意空树高度为零
  return root->h;
}

void updateh(node *root) { //更新高度
  root->h = max(getheight(root->left), getheight(root->right)) + 1;
}

void L(node *&root) { //左旋操作
  node *temp = root->right;
  root->right = temp->left;
  temp->left = root;
  updateh(root);
  updateh(temp);
  root = temp;
}

void R(node *&root) { //右旋操作
  node *temp = root->left;
  root->left = temp->right;
  temp->right = root;
  updateh(root);
  updateh(temp);
  root = temp;
}

void insert(node *&root, int data) { //核心函数，插入操作
  if (!root) {
    root = new node;
    root->data = data;
    root->h = 1;
    root->left = root->right = NULL;
    return;
  }
  if (data < root->data) {
    insert(root->left, data);
    updateh(root);
    if (getheight(root->left) - getheight(root->right) == 2) { //左边不平衡
      if (getheight(root->left->left) - getheight(root->left->right) ==
          1) { // LL类型，只需对根节点右旋
        R(root);
      } else if (
          getheight(root->left->left) - getheight(root->left->right) ==
          -1) { // LR类型，先对左子树进行左旋转化成LL型，再对根节点做右旋操作
        L(root->left);
        R(root);
      }
    }
  } else {
    insert(root->right, data);
    updateh(root);
    if (getheight(root->left) - getheight(root->right) == -2) { //右子树不平衡
      if (getheight(root->right->left) - getheight(root->right->right) ==
          -1) { // RR型，只需对根节点做左旋操作
        L(root);
      } else if (
          getheight(root->right->left) - getheight(root->right->right) ==
          1) { // RL类型，先做右子树做右旋，转化成RR型，在对根节点做左旋操作
        R(root->right);
        L(root);
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  node *root = NULL;
  for (int i = 0; i < n; i++) { //建树过程
    int t;
    scanf("%d", &t);
    insert(root, t);
  }
  printf("%d", root->data); //输出根节点数据
  return 0;
}
