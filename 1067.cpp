#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;
        p[k] = i;
    }
    int count = 0, start = 1;
    while (true) {
        if (p[0] == 0) {
            bool c = true;
            for (int i = start; i < n; i++) {
                if (p[i] != i) {
                    start = i;
                    swap(p[0], p[i]);
                    count ++;
                    c = false;
                    break;
                }
            }
            if (c) {
                cout << count;
                break;
            }
        } else {
            swap(p[0], p[p[0]]);
            count ++;
        }
    }
}