#include<iostream>
#include<algorithm>
#define MMAX 100000
using namespace std;

int left(int root) {
    return root * 2 + 1;
}

int right(int root) {
    return root * 2 + 2;
}

bool compare(int a, int b, int cmp) {
    if (cmp) return a <= b;
    else return a >= b;
}

bool judge(int * data, int root, int hNum, bool cmp) {
    bool flag = true;
    if (left(root) < hNum) {
        if (!compare(data[root], data[left(root)], cmp)) return false;
        flag = flag && judge(data, left(root), hNum, cmp);
    }
    if (right(root) < hNum) {
        if (!compare(data[root], data[right(root)], cmp)) return false;
        flag = flag && judge(data, right(root), hNum, cmp);
    }
    return flag;
}

bool s;
void print(int * data, int root, int hNum) {
    if (left(root) < hNum) print(data, left(root), hNum);
    if (right(root) < hNum) print(data, right(root), hNum);
    if (s) s = false;
    else cout << " ";
    cout << data[root];
}

int main() {
    int n, hNum;
    cin >> n >> hNum;
    for (int i = 0; i < n; i++) {
        int data[MMAX];
        for (int h = 0; h < hNum; h++) {
            cin >> data[h];
        }
        if (judge(data, 0, hNum, false)) cout << "Max Heap" << endl;
        else if (judge(data, 0, hNum, true)) cout << "Min Heap" << endl;
        else cout << "Not Heap" << endl;
        s = true;
        print(data, 0, hNum);
        cout << endl;
    }
}