#include<iostream>
#include<vector>
#define MMAX 100010
using namespace std;

int Price[MMAX];
int Super[MMAX];
vector<int> retailers;

void has(int r) {
    if(Price[r] == 0) {
        has(Super[r]);
        Price[r] = Price[Super[r]] + 1;
    }
}

int main() {
    int n;
    double price, rate;
    cin >> n >> price >> rate;
    rate = rate * 0.01 + 1;
    for(int i = 0; i < n; i++) {
        int k;  cin >> k;
        for(int j = 0; j < k; j++) {
            int s;  cin >> s;
            Super[s] = i;
        }
        if(k == 0) retailers.push_back(i);
    }
    Price[0] = 1;
    int min = n + 1;
    for(auto r: retailers) {
        has(r);
        if(Price[r] < min) min = Price[r];
    }
    int count = 0;
    for(auto r: retailers) {
        if(Price[r] == min) count++;
    }
    for(int i = 2; i <= min; i++) {
        price *= rate;
    }
    printf("%.4f %d", price, count);
}