#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

string intToString(int n, int radix) {
    string number = "";
    while(n) {
        number += (n % radix + '0');
        n /= radix;
    }
    reverse(number.begin(), number.end());
    // cout << number  << endl;
    return number;
}

int stringToInt(string number, int radix) {
    int result = 0;
    for(int i = 0; i < number.length(); i++) {
        result *= radix;
        result += number[i] - '0';
    }
    // cout << number <<  endl;
    return result;
}

bool judgePrime(int n) {
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int number;
    cin >> number;
    while(number >= 0) {
        int radix;
        cin >> radix;
        bool flag = true;
        if(!judgePrime(number)) flag = false;
        else {
            string s = intToString(number, radix);
            reverse(s.begin(), s.end());
            if(!judgePrime(stringToInt(s, radix))) flag = false;
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
        // cout <<  "--------------------" << endl;
        cin >> number;
    }
}