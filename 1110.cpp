#include<iostream>
#include<algorithm>
#include<queue>
#define MMAX 10000
using namespace std;

struct Node {
    int father, left, right;
    Node() {
        father = left = right = -1;
    }
};

Node nodes[MMAX];

int convert(string a) {
    try {
        return stoi(a);
    }
    catch (exception e) {
        return -1;
    }
}

void add(int f, int l, int r) {
    nodes[f].left = l;
    nodes[f].right = r;
    if (l != -1) nodes[l].father = f;
    if (r != -1) nodes[r].father = f;
}


int DFS(int root, int n) {
    int p = root, cnt = 0;
    bool flag = true;
    queue<int> q;
    q.push(root);
    while(q.size()) {
        p = q.front();
        // cout << p << endl;
        q.pop();
        cnt++;
        if ((nodes[p].left == -1 && nodes[p].right != -1)) return -1;
        else if (nodes[p].left != -1 && nodes[p].right == -1 && flag) {
            flag = false;
            q.push(nodes[p].left);
            // cout << nodes[p].left << " been pushed." << endl;
        }
        else if (nodes[p].left != -1 && nodes[p].right != -1 && flag) {
            q.push(nodes[p].left);
            // cout << nodes[p].left << " been pushed." << endl;
            q.push(nodes[p].right);
            // cout << nodes[p].right << " been pushed." << endl;
        }
        else flag = false;
    }
    if (cnt == n) return p;
    return -1;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        add(i, convert(l), convert(r));
    }
    int root;
    for (root = 0; root < n; root++) {
        if (nodes[root].father == -1) break;
    }
    int result = DFS(root, n);
    if (result != -1) cout << "YES " << result;
    else cout << "NO " << root;
    return 0;
}