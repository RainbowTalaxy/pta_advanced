#include<iostream>
#include<vector>
#include<cmath>
#define MMAX 100000
using namespace std;

struct Node
{
    int value;
    int next;
};

Node nodes[MMAX];
bool visit[MMAX];

bool isVisited(int root) {
    int k = abs(nodes[root].value);
    if(visit[k]) return true;
    else {
        visit[k] = true;
        return false;
    }
}

int main() {
    int root, nodeNum;
    cin >> root >> nodeNum;
    for(int i = 0; i < nodeNum; i++) {
        int id; cin >> id;
        cin >> nodes[id].value >> nodes[id].next;
    }
    vector<int> fives;
    fill(visit, visit + MMAX, false);
    printf("%05d %d", root, nodes[root].value);
    isVisited(root);
    while(nodes[root].next != -1) {
        root = nodes[root].next;
        if(!isVisited(root)) {
            printf(" %05d\n%05d %d", root, root, nodes[root].value);
        }
        else {
            fives.push_back(root);
        }
    }
    cout << " -1\n";
    bool first = true;
    for(auto f: fives) {
        if(first) {
            first = false;
            printf("%05d %d", f, nodes[f].value);
        }
        else {
            printf(" %05d\n%05d %d", f, f, nodes[f].value);
        }
    }
    if(!first) cout << " -1\n";
    return 0;
    

}