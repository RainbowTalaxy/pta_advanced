#include<iostream>
#include<vector>
#include<queue>
#define MAXNUM 100
using namespace std;

typedef struct {
    vector<int> children;
} People;

void add_child(People people[], int father, int child) {
    people[father].children.push_back(child);
}

void BFS(People people[], int root, int noChild[]) {
    int level = 0;
    queue<int> personToFind;
    personToFind.push(root);
    personToFind.push(0);
    while(!personToFind.empty()) {
        if(personToFind.front()) {
            int person = personToFind.front();
            personToFind.pop();
            if(people[person].children.empty()) noChild[level] ++;
            else {
                for(auto child: people[person].children) {
                    personToFind.push(child);
                }
            }
        }
        else {
            level ++;
            personToFind.pop();
            if(personToFind.back()) {
                personToFind.push(0);
            }
        }
    }
    noChild[level] = -1;
}

int main() {
    int n, m;
    int noChild[MAXNUM] = {0};
    People people[MAXNUM];
    cin >> n >> m;
    for(int person = 0; person < m; person ++) {
        int father, childNum;
        cin >> father >> childNum;
        int child;
        for(int i = 0; i < childNum; i++) {
            cin >> child;
            add_child(people, father, child);
        }
    }
    BFS(people, 1, noChild);
    for(int level = 0; noChild[level] != -1; level ++) {
        if(level) cout << " ";
        cout << noChild[level];
    }
    return 0;
}