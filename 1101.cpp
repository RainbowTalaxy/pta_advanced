#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int list[100000];
    bool pivot[100000];
    for(int i = 0; i < n; i++) {
        cin >> list[i];
        pivot[i] = true;
    }
    int max = -1;
    for(int i = 0; i < n; i++) {
        if(list[i] > max) max = list[i];
        else pivot[i] = false;
    }
    int min = 1000000001;
    for(int i = n - 1; i >= 0; i--) {
        if(list[i] < min) min = list[i];
        else pivot[i] = false;
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(pivot[i]) count++;
    }
    cout << count << endl;
    // if(count) cout << endl;
    // else return 0;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(pivot[i]) {
            if(flag) flag = false;
            else cout << " ";
            cout << list[i];
        }
    }
    cout << endl;
    return 0;
}