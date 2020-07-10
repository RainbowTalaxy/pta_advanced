#include<iostream>
#include<vector>
#include<string>
using namespace std;

const string digit[10] = {
    "zero", "one", "two", "three",
    "four", "five", "six", "seven",
    "eight", "nine"
};

int main() {
    string s;
    int sum = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        sum += stoi(s.substr(i, 1));
    }
    vector<int> num;
    do {
        num.push_back(sum % 10);
        sum /= 10;
    } while(sum);
    vector<int>::reverse_iterator it = num.rbegin();
    int flag = 1;
    for(; it != num.rend(); it ++) {
        if(flag) flag --;
        else cout << " ";
        cout << digit[*it];
    }
    return 0;
}