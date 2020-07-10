#include<iostream>
#include<set>
using namespace std;

int main() {
    set<int> k;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        k.insert(m);
    }
    for (int i = 1; i <= n; i++) {
        if (k.count(i) == 0) {
            cout << i;
            return 0;
        }
    }
}