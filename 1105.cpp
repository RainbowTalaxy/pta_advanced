#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define MMAX 10000
using namespace std;

bool cmp(int a, int b) {
    return a < b;
}

int store[MMAX][MMAX];
vector<int> numbers;
//m hang n lie
int main() {
    int N; cin >> N;
    int n, m;
    for(n = sqrt(N); n >= 1; n--) {
        m = N / n;
        if(n * m == N) break;
    }
    int x = -1, y = 0;
    int dx = 1, dy = 0;
    int left = -1, right = n - 1, top = 0, buttom = m - 1;
    for(int i = 0; i < N; i++) {
        int k; cin >> k;
        numbers.push_back(k);
    }
    sort(numbers.begin(), numbers.end(), cmp);
    for(int i = 0; i < N; i++) {
        x += dx;
        y += dy;
        // cout << y << " " << x << " " << right << endl;
        store[y][x] = numbers.back();
        numbers.pop_back();
        if(x == right && y == top) {
            dx = 0;
            dy = 1;
            left++;
        }
        else if(x == right && y == buttom) {
            dx = -1;
            dy = 0;
            top++;
        }
        else if(x == left && y == buttom) {
            dx = 0;
            dy = -1;
            right--;
        }
        else if(x == left && y == top) {
            dx = 1;
            dy = 0;
            buttom--;
        }
    }
    for(int i = 0; i < m; i++) {
        if(i) cout << endl;
        for(int j = 0; j < n; j++) {
            if(j) cout << " ";
            cout << store[i][j];
        }
    }
}