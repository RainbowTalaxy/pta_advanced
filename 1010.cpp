#include<iostream>
#include<string>
using namespace std;

long long stringToint(string n, int radix) {
    long long number = 0;
    string::iterator it = n.begin();
    string::iterator end = n.end();
    for(; it != end; it++) {
        number *= radix;
        if(number < 0) return -1887415158;
        if((*it) <= '9' && (*it) >= '0' && (*it) - '0' >= radix) return -1887415157;
        else if((*it) >= 'a' && (*it) - 'a' + 10 >= radix) return -1887415157;
        else if((*it) <= '9' && (*it) >= '0') number += (*it) - '0';
        else number += (*it) - 'a' + 10;
        if(number < 0) return -1887415158;
    }
    return number;
}

int binarySearch(string s, long long number, long long left, long long right) {
    if(left > right || left < 2) return 0;
    long long mid = (left + right) / 2;
    // cout << left << " " << mid << " " << right <<endl;
    long long n = stringToint(s, mid);
    // cout << n << " " << number << endl;
    // cout << "-------------------" << endl;
    if(n == -1887415157)  {
        return binarySearch(s, number, mid + 1, right);
    }
    else if(n == -1887415158) {
        int end = binarySearch(s, number, left, mid - 1);
        if(end) return end;
        else return binarySearch(s, number, mid + 1, right);
    }
    else if(n == number) {
        int end = binarySearch(s, number, left, mid - 1);
        if(end) return end;
        else return mid;
    }
    else if (n < number) return binarySearch(s, number, mid + 1, right);
    else return binarySearch(s, number, left, mid - 1);
}

int main() {
    string number1, number2;
    int tag, num_radix;
    cin >> number1 >> number2;
    cin >> tag >> num_radix;
    if(tag == 1) {
        long long n1 = stringToint(number1, num_radix);
        int radix = binarySearch(number2, n1, 2, n1);
        if(radix) cout << radix;
        else cout << "Impossible";
        return 0;
    }
    if(tag == 2) {
        long long n2 = stringToint(number2, num_radix);
        int radix = binarySearch(number1, n2, 2, n2);
        if(radix) cout << radix;
        else cout << "Impossible";
        return 0;
    }
}