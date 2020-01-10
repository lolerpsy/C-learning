#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int pre[35], in[35];
bool comp(int a, int b) { return abs(a) < abs(b); }
struct node {
    int data;
    struct node *l, *r;
};
node *creat(int prel, int prer, int inl, int inr) {
    if (prel > prer)
        return NULL;
    node *root = new node;
    root->data = pre[prel];
    int i = inl;
    while (i <= inr && in[i] != pre[prel])
        i++;
    root->l = creat(prel + 1, prel + i - inl, inl, i - 1);
    root->r = creat(prel + i - inl + 1, prer, i + 1, inr);
    return root;
}
bool judge1(node *root) {
    if (!root)
        return true;
    if (root->data < 0) {
        if (root->l && root->l->data < 0)
            return false;
        if (root->r && root->r->data < 0)
            return false;
    }
    return judge1(root->l) && judge1(root->r);
}
int getblacknum(node *root) {
    if (!root)
        return 0;
    return root->data > 0 ? max(getblacknum(root->l), getblacknum(root->r)) + 1
                          : max(getblacknum(root->l), getblacknum(root->r));
}
bool judge2(node *root) {
    if(!root) return true;
    if(getblacknum(root->l)!=getblacknum(root->r)) return false;
    return judge2(root->l) && judge2(root->r);
}
int main() {
    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &pre[j]);
            in[j] = pre[j];
        }
        sort(in, in + n, comp);
        node *root = creat(0, n - 1, 0, n - 1);
        printf("%s\n", pre[0]>0 && judge1(root) && judge2(root) ? "Yes" : "No");
    }
    return 0;
}
