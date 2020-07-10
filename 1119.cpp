#include<iostream>
#include<vector>
#include<queue>
#define MMAX 100000
using namespace std;

struct Area {
    int left, right;
    Area(int l, int r) {
        left = l;
        right = r;
    }
    bool isVaild() {
        return left <= right;
    }
};

struct Node {
    int left, right;
};

int pre[MMAX], post[MMAX];
Node nodes[MMAX];
bool isUnique = true, space = true;

vector<Area> findLeft(Area preA, Area postA) {
    int preRoot = pre[preA.left], i;
    for(i = postA.left; i <= postA.right; i++) {
        if(post[i] == preRoot) break;
    }
    vector<Area> areas;
    areas.push_back(Area(preA.left, i + preA.left - postA.left));
    areas.push_back(Area(postA.left, i));
    return areas;
}

int buildTree(Area preA, Area postA) {
    // cout << "---------------------------" << endl;
    // preA.print();   postA.print();
    if(!preA.isVaild()) return 0;
    int root = pre[preA.left], leftRoot, rightRoot;;
    preA.left++;
    postA.right--;
    if(!preA.isVaild()) return root;
    vector<Area> areas = findLeft(preA, postA);
    Area lpre = areas[0];
    Area lpost = areas[1];
    Area rpre = Area(lpre.right + 1, preA.right);
    Area rpost = Area(lpost.right + 1, postA.right);
    leftRoot = buildTree(lpre, lpost);
    rightRoot = buildTree(rpre, rpost);
    if(leftRoot != 0 && rightRoot == 0) isUnique = false;
    nodes[root].left = leftRoot;
    nodes[root].right = rightRoot;
    return root;
}

void BFS(int root) {
    if(nodes[root].left) BFS(nodes[root].left);
    if(space) space = false;
    else cout << " ";
    cout << root;
    if(nodes[root].right) BFS(nodes[root].right);
}

int main() {
    int n, root;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> post[i];
    root = buildTree(Area(0, n - 1), Area(0, n - 1));
    // for(int i = 1; i <= n; i++) {
    //     cout << i << " left: " << nodes[i].left << " right: " << nodes[i].right << endl;
    // }
    if(isUnique) cout << "Yes" << endl;
    else cout << "No" << endl;
    BFS(root);
    return 0;
}