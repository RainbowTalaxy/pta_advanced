#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

bool cmp(string s1, string s2) {
    return s1 + s2 < s2 + s1;
}

int main() {
    int n;
    cin >> n;
    vector<string> nums;
    for (int i = 0; i < n; i += 1) {
        string s;
        cin >> s;
        nums.push_back(s);
    }
    sort(nums.begin(), nums.end(), cmp);
    string result = "";
    for (auto num: nums) {
        result += num;
    }
    while (result[0] == '0') {
        result.erase(result.begin());
    }
    if (result.size()) cout << result;
    else cout << 0;
}