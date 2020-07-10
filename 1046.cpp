#include<iostream>
#include<algorithm>
#define MMAX 10001
using namespace std;

int main() {
    int distance[MMAX];
    distance[0] = 0;
    int n; cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        sum += k;
        distance[i] = sum;
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int c = abs(distance[b - 1] - distance[a - 1]);
        cout << min(c, sum - c) << endl;
    }
    return 0;
}