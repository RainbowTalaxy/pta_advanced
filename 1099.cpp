#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAXNODE 1000
using namespace std;

typedef struct {
    int data;
    int left;
    int right;
} Node;

Node nodes[MAXNODE];
queue<int> inorder;
vector<int> bfs;
int datas[MAXNODE];

void link_node(int father, int left, int right) {
    nodes[father].left = left;
    nodes[father].right = right;
}

void inOrder(int node) {
    if(nodes[node].left != -1) inOrder(nodes[node].left);
    inorder.push(node);
    if(nodes[node].right != -1) inOrder(nodes[node].right);
}

void BFS(int root) {
    queue<int> toTravel;
    toTravel.push(root);
    while(!toTravel.empty()) {
        int k = toTravel.front();
        // cout << k << endl;
        bfs.push_back(nodes[k].data);
        toTravel.pop();
        if(nodes[k].left != -1) toTravel.push(nodes[k].left);
        if(nodes[k].right != -1) toTravel.push(nodes[k].right);
    }
}

int compare(int a, int b) {
    return a < b;
}


int main() {
    int nodeNum;
    cin >> nodeNum;
    for(int node = 0; node < nodeNum; node++) {
        int left, right;
        cin >> left >> right;
        link_node(node, left, right);
    }
    for(int i = 0; i < nodeNum; i++) {
        cin >> datas[i];
    }
    sort(datas, datas + nodeNum, compare);
    inOrder(0);
    for(int i = 0; i < nodeNum; i++) {
        nodes[inorder.front()].data = datas[i];
        inorder.pop();
    }
    BFS(0);
    bool flag = true;
    for(auto b: bfs) {
        if(flag) flag = false;
        else cout << " ";
        cout << b;
    }
    return 0;
}

