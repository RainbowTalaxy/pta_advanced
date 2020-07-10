#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

void chooseMax(double w, double t, double l, string &s, double &result) {
    if(w >= t && w >= l) {
        s += "W";
        result *= w;
    }
    else if (t >= w && t >= l) {
        s += "T";
        result *= t;
    }
    else {
        s += "L";
        result *= l;
    }
}

int main() {
    int n = 3;
    string result = "";
    double bet_result = 1;
    for(int i = 0; i < 3; i++) {
        double w, t, l;
        cin >> w >> t >> l;
        chooseMax(w, t, l, result, bet_result);
    }
    for(int i = 0; i < 3; i++) {
        cout << result[i] << " ";
    }
    printf("%.2f", (bet_result * 0.65 - 1) * 2);
    return 0;
}