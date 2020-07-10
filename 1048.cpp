#include<iostream>
using namespace std;

int main() {
    int a[1001] = {0};
    int coinNum, requirement;
    cin >> coinNum >> requirement;
    for (int i = 0; i < coinNum; i++) {
        int coin;
        cin >> coin;
        a[coin]++;
    }
    for (int i = 0; i <= requirement / 2; i++) {
        if (a[i] && a[requirement - i]) {
            if (i == requirement - i) {
                if (a[i] == 2) {
                    cout << i << " " << i;
                    return 0;
                }
            } else {
                cout << i << " " << requirement - i;
                return 0;
            }
        }
    }
    cout << "No Solution";
}