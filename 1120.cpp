#include<iostream>
#include<set>
using namespace std;

int add(int k) {
    int sum = 0;
    while(k) {
        sum += (k % 10);
        k /= 10;
    }
    return sum;
}

int main() {
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        s.insert(add(k));
    }
    cout << s.size() << endl;
    bool flag = true;
    for (auto i: s) {
        if (flag) flag = false;
        else cout << " ";
        cout << i;
    }
}