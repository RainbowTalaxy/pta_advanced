#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

int father[11];
int left_t[11];
int right_t[11];

void BFS(int root) {
    bool flag = true;
    queue<int> sons;
    sons.push(root);
    while(!sons.empty()) {
        int k = sons.front();
        sons.pop();
        if(flag) flag = false;
        else cout << " ";
        cout << k;
        if(left_t[k] != -1) sons.push(left_t[k]);
        if(right_t[k] != -1) sons.push(right_t[k]);
    }
}

bool inorder = true;
void inOrder(int root) {
    if(left_t[root] != -1) inOrder(left_t[root]);
    if(inorder) inorder = false;
    else cout << " ";
    cout << root;
    if(right_t[root] != -1) inOrder(right_t[root]);
}

int main() {
    fill(father, father + 11, -1);
    fill(left_t, left_t + 11, -1);
    fill(right_t, right_t + 11, -1);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if(a != "-") {
            int k = stoi(a);
            right_t[i] = k;
            father[k] = i;
        }
        if(b != "-") {
            int k = stoi(b);
            left_t[i] = k;
            father[k] = i;
        }
    }
    for(int i = 0; i < n; i++) {
        if(father[i] == -1) {
            // cout << i;
            BFS(i);
            cout << endl;
            inOrder(i);
            break;
        }
    }
    // for(int i = 0; i < n; i++) {
    //     cout << i << " " << father[i] << endl;
    // }
}