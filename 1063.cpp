#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
    int n;
    vector<set<int>> sets;
    cin >> n;
    for (int i = 0; i < n; i += 1) {
        int m, e;
        cin >> m;
        set<int> s;
        for (int j = 0; j < m; j += 1) {
            cin >> e;
            s.insert(e);
        }
        sets.push_back(s);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int count = 0, a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        for (auto e: sets[a]) {
            if (sets[b].count(e)) {
                count += 1;
            }
        }
        printf("%.1f%%\n", count * 100.0 / (sets[a].size() + sets[b].size() - count));
    }
}