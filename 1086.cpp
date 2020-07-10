#include<iostream>
#include<vector>
using namespace std;

struct Record {
    bool isPush;
    int value;
    Record(bool i, int v) {
        isPush = i;
        value = v;
    }
};

vector<Record> records;

struct Range {
    int left, right;
    Range(int l, int r) {
        left = l;
        right = r;
    }
    bool isValid() {
        return left >= right;
    }
    Range getLeft() {
        int pushCount = 0, popCount = 0;
        for (int i = left + 1; i < right; i++) {
            if (records[i].isPush) pushCount++;
            else popCount++;
            if (popCount > pushCount) return Range(left + 1, i);
        }
        return Range(left + 1, right);
    }
};

struct Node {
    int value, left, right;
    Node() {
        value = -1; left = -1, right = -1;
    }
    Node(int l, int r) {
        left = l;
        right = r;
    }
};

Node nodes[31];

int getTree(Range range) {
    if (range.isValid()) return -1;
    int root = records[range.left].value;
    Range lr = range.getLeft();
    Range rr = Range(lr.right + 1, range.right);
    nodes[root].left = getTree(lr);
    nodes[root].right = getTree(rr);
    return root;
}

bool flag = true;
void postTravel(int root) {
    if (nodes[root].left != -1) postTravel(nodes[root].left);
    if (nodes[root].right != -1) postTravel(nodes[root].right);
    if (flag) flag = 0;
    else cout << " ";
    cout << root;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n * 2; i++) {
        string s;
        cin >> s;
        if (s == "Push") {
            int v;
            cin >> v;
            records.push_back(Record(true, v));
        } else {
            records.push_back(Record(false, -2));
        }
    }
    int root = getTree(Range(0, n * 2));
    postTravel(root);
}