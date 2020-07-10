#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
    string number;
    int n;
    char t[10];
    cin >> n;
    sprintf(t, "%04d", n);
    number = t;
    do {
        sort(number.begin(), number.end());
        string rvs = number;
        reverse(rvs.begin(), rvs.end());
        string result;
        char t[10];
        sprintf(t, "%04d", stoi(rvs) - stoi(number));
        result = t;
        cout << rvs << " - " << number << " = " << result << endl;
        number = result;
    } while (number != "6174" && number != "0000");
}