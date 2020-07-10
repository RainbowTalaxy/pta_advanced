#include<iostream>
#include<map>
#define MMAX 50001
using namespace std;

struct Tree {
    int left = -1, right = -1;
};

map<int, Tree> trees;

struct Range {
    int left = 0, right = MMAX;
    Range(int l, int r) {
        left = l;
        right = r;
    }
    bool isValid() {
        return left <= right;
    }
};

int buildTree(int * pre, int * in, Range rp, Range ri) {
    if (!rp.isValid() || !ri.isValid()) return -1;
    int root = pre[rp.left], i;
    for (i = ri.left; i <= ri.right; i++) {
        if (in[i] == root) break;
    }
    int lroot = buildTree(pre, in, 
        Range(rp.left + 1, rp.left + i - ri.left), Range(ri.left, i - 1));
    int rroot = buildTree(pre, in, 
        Range(rp.left + 1 + i - ri.left, rp.right), Range(i + 1, ri.right));
    trees[root].left = lroot;
    trees[root].right = rroot;
    return root;
}

bool hasPrint = true;
void postOrder(int root) {
    int l = trees[root].left, r = trees[root].right;
    if (l != -1) postOrder(l);
    if (r != -1) postOrder(r);
    if (hasPrint) cout << root;
    hasPrint = false;
}

int main() {
    int n, pre[MMAX], in[MMAX];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> in[i];
    int root = buildTree(pre, in, Range(0, n - 1), Range(0, n - 1));
    postOrder(root);
    return 0;
}