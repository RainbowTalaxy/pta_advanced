#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<sstream>
#define MMAX 2000
using namespace std;

struct V {
    set<int> links;
};

V vs[MMAX];
int vNum, eNum;

vector<int> transfer(string s) {
    stringstream ss;
    vector<int> vt;
    int i;
    ss << s;
    while(ss >> i) {
        vt.push_back(i);
    }
    return vt;
}

bool find(vector<int> toPair) {
    set<int> st;
    for (auto p: toPair) {
        for (auto l: vs[p].links) {
            if (st.count(l)) return false;
        }
        st.insert(p);
    }
    return true;
}

int main() {
    cin >> vNum >> eNum;
    for (int e = 0; e < eNum; e++) {
        int a, b;
        cin >> a >> b;
        vs[a].links.insert(b);
    }
    int k;
    cin >> k;
    cin.get();
    bool flag = true;
    for (int i = 0; i < k; i++) {
        string s;
        getline(cin, s);
        vector<int> vt = transfer(s);
        if (!find(vt)) {
            if (flag) flag = false;
            else cout << " ";
            cout << i;
        }
    }
    return 0;
}