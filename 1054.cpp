#include<iostream>
#include<map>
using namespace std;

int main() {
    int col, row;
    map<int, int> counter;
    cin >> col >> row;
    int half = col * row / 2;
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            int num;
            scanf("%d", &num);
            counter[num] += 1;
            if (counter[num] > half) {
                cout << num;
                return 0;
            }
        }
    }
}
