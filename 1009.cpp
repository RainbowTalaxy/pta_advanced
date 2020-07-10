#include<iostream>
#include<map>
using namespace std;

void addKey(map<int, double> &m, int key, double value) {
    if (m.count(key) == 0) m[key] = value;
    else m[key] += value;
}

void inputAdd(map<int, double> &m) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int key;
        double value;
        cin >> key >> value;
        addKey(m, key, value);
    }
}

void multiply(map<int, double> &m1, map<int, double> &m2, map<int, double> &result) {
    map<int, double>::iterator it = m1.begin();
    map<int, double>::iterator end = m1.end();
    for(; it != end; it++) {
        map<int, double>::iterator it2 = m2.begin();
        map<int, double>::iterator end2 = m2.end();
        for(; it2 != end2; it2++) {
            addKey(result, it->first + it2->first , it->second * it2->second);
        }
    }
}

int main()
{
    map<int, double> m1;
    map<int, double> m2;
    map<int, double> result;
    inputAdd(m1);
    inputAdd(m2);
    multiply(m1, m2, result);
    int count = 0;
    for(auto v: result) {
        if(v.second !=  0) count++;
    }
    cout << count;
    // cout << m.size();
    if (result.size() > 0) {
        map<int, double>::iterator it = result.end();
        map<int, double>::iterator end = result.begin();
        bool flag = true;
        for(it --; it != end || flag; it --) {
            // cout << " " << it->first << " " << it->second;
            if (it->second != 0)
                printf(" %d %.1f", it->first, it->second);
            if(it == end) break;
        }
    }
    return 0;
}