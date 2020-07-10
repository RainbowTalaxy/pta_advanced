#include<iostream>

using namespace std;
int main() {
    long long n;
    cin >> n;
    int k[10] = {0};
    long long number = n;
    do {
        k[number % 10]++;
        number /= 10;
    } while(number);
    int s[10] = {0};
    number = n * 2;
    do {
        s[number % 10]++;
        number /= 10;
    } while(number);
    for(int i = 0; i < 10; i++) {
        if(k[i] != s[i]) {
            cout << "No" << endl;
            cout << n * 2;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << n * 2;
    return 0;
}