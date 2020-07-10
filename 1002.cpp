#include<iostream>
#include<map>
using namespace std;

void inputAdd(map<int, double> &m) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int key;
        double value;
        cin >> key >> value;
        if (m.count(key) == 0) m[key] = value;
        else m[key] += value;
    }
}

int main()
{
    map<int, double> m;
    inputAdd(m);
    inputAdd(m);
    int count = 0;
    for(auto &v: m) {
        if(v.second !=  0) count++;
    }
    cout << count;
    // cout << m.size();
    if (m.size() > 0) {
        map<int, double>::iterator it = m.end();
        map<int, double>::iterator end = m.begin();
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