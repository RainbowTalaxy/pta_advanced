#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string mars[2][13] = {
    {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
    {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}
};

int toEarth(string s) {
    stringstream ss; ss << s;
    if(s.find(' ') != string::npos) {
        string a, b;
        int i, j;
        ss >> a >> b;
        for(i = 0; i < 13; i++) {
            if(a == mars[1][i]) break;
        }
        for(j = 0; j < 13; j++) {
            if(b == mars[0][j]) break;
        }
        return i * 13 + j;
    }
    else {
        string a;
        int i;
        ss >> a;
        for(i = 0; i < 13; i++) {
            if(a == mars[0][i]) break;
        }
        if(i == 13) {
            for(i = 0; i < 13; i++) {
                if(a == mars[1][i]) return i * 13;
            }
        }
        return i;
    }
}

string toMars(int n) {
    if(n < 13) return mars[0][n];
    int a = n % 13;
    int b = n / 13;
    if(a == 0) return mars[1][b];
    return mars[1][b] + " " + mars[0][a];
}

int main() {
    int n; cin >> n; cin.get();
    string s;
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        if(i) cout << endl;
        if(s[0] >= '0' && s[0] <= '9') cout << toMars(stoi(s));
        else cout << toEarth(s);
    }
    return 0;
}