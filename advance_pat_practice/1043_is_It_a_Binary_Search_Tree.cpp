#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> origin, pre, post;

bool mirror = false;

struct node {
    int data;
    node *lchild, *rchild;
};

void insert(node *&root, int data) {
    if (root == NULL) {
        root = new node;
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        return;
    }
    if (data < root->data)
        insert(root->lchild, data);
    else
        insert(root->rchild, data);
}

void pretravel(node *root) {
    if (!root)
        return;
    pre.push_back(root->data);
    if (!mirror) {
        pretravel(root->lchild);
        pretravel(root->rchild);
    } else {
        pretravel(root->rchild);
        pretravel(root->lchild);
    }
}

void posttravel(node *root) {
    if (!root)
        return;
    if (!mirror) {
        posttravel(root->lchild);
        posttravel(root->rchild);
    } else {
        posttravel(root->rchild);
        posttravel(root->lchild);
    }
    post.push_back(root->data);
}

int main() {
    int n;
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        origin.push_back(x);
        insert(root, x);
    }

    bool flag;
    pretravel(root);
    if (pre == origin) {
        flag = true;
    } else {
        mirror = true;
        pre.clear();
        pretravel(root);
        if (pre == origin) {
            flag = true;
        } else {
            flag = false;
        }
    }

    if (flag) {
        printf("YES\n");
        posttravel(root);
        for (int i = 0; i < n; i++) {
            if (i)
                printf(" ");
            printf("%d", post[i]);
        }
    } else
        printf("NO\n");

    return 0;
}
