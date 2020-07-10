#include<iostream>
#include<string>
#include<set>
#include<ctype.h>
using namespace std;

int main() {
    string content, output;
    getline(cin, content);
    getline(cin, output);
    set<char> normalKeys, brokenKeys;
    for (auto i: output) {
        normalKeys.insert(toupper(i));
    }
    for (auto i: content) {
        char c = toupper(i);
        if (!normalKeys.count(c) && !brokenKeys.count(c)) {
            cout << c;
            brokenKeys.insert(c);
        }
    }
}