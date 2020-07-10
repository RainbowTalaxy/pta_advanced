#include<iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    double k, sum = 0;
    for(long long i = 0; i < n; i++) {
        cin >> k;
        sum += k * (i - 0 + 1) * (n - i);
    }
    printf("%.2f", sum);
    return 0;
}