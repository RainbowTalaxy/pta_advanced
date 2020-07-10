#include<iostream>
#include<vector>
#define MMAX 10001
using namespace std;

typedef struct {
    vector<int> linked;
    bool is_visited;
} Node;

Node nodes[MMAX];
int nodeNum;
int deepest = 0, components = 0;

void initNode(int i) {
    nodes[i].is_visited = false;
}

void linkNode(int n1, int n2) {
    nodes[n1].linked.push_back(n2);
    nodes[n2].linked.push_back(n1);
}

int countDeep(int root) {
    int count = 0;
    if(!nodes[root].is_visited) {
        for(auto linknode: nodes[root].linked) {
            nodes[root].is_visited = true;
            int height = countDeep(linknode) + 1;
            if(height > count) count = height;
            nodes[root].is_visited = false;
        }
    }
    return count;
}

void DFS(int root) {
    if(!nodes[root].is_visited) {
        for(auto linknode: nodes[root].linked) {
            nodes[root].is_visited = true;
            DFS(linknode);
        }
    }
}

int main() {
    cin >> nodeNum;
    for(int node = 1; node <= nodeNum; node++) initNode(node);
    for(int node = 1; node <= nodeNum - 1; node++) {
        int n1, n2;
        cin >> n1 >> n2;
        linkNode(n1, n2);
    }
    int heights[MMAX];
    for(int node = 1; node <= nodeNum; node++) {
        heights[node] = countDeep(node);
        if(deepest < heights[node]) deepest = heights[node];
    }
    for(int node = 1; node <= nodeNum; node++) {
        if(!nodes[node].is_visited) {
            components++;
            DFS(node);
        }
    }
    if(components > 1) cout << "Error: " << components << " components";
    else {
        for(int node = 1; node <= nodeNum; node++) {
            if(heights[node] == deepest) cout << node << endl;
        }
    }
    return 0;
}