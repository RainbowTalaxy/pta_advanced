#include<iostream>
using namespace std;
int n[10000];

bool isP(int num) {
    for(int i = 0; i <= num / 2; i++) {
        if(n[i] != n[num - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int number, base, num = 0;
    cin >> number >> base;
    do {
        n[num] = number % base;
        number /= base;
        num++;
    } while(number != 0);
    if(isP(num)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    for(int i = num - 1; i >= 0; i--) {
        cout << n[i];
        if(i) cout << " ";
    }
    return 0;
}