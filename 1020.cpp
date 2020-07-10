#include<iostream>
#include<stdlib.h>
#include<queue>
#define MMAX 10000
using namespace std;

typedef struct Node {
    int data;
    Node * left;
    Node * right;
} Node;

int midOrder[MMAX], postOrder[MMAX];

Node * createNode(int data) {
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node * buildTree(int pl, int pr, int ml, int mr) {
    int root = postOrder[pr];
    Node * node = createNode(root);
    int mid;
    for(mid = ml; mid <= mr; mid++) {
        if(midOrder[mid] == root) break;
    }
    if(mid != ml) node->left = buildTree(pl, pl + mid - 1 - ml, ml, mid - 1);
    if(mid != mr) node->right = buildTree(pl + mid - ml, pr - 1, mid + 1, mr);
    return node;
}

void BFS(Node * node) {
    if(node == NULL) return;
    queue<Node *> q;
    q.push(node);
    bool bf = true;
    while(!q.empty()) {
        Node * f = q.front();
        q.pop();
        if(f) {
            q.push(f->left);
            q.push(f->right);
            if(bf) bf = false;
            else cout << " ";
            cout << f->data;
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> postOrder[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> midOrder[i];
    }
    Node * node = buildTree(0, n - 1, 0, n - 1);
    BFS(node);
    return 0;
}