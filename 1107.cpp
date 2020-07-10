#include<iostream>
#include<vector>
#include<map>
#include<set>
#define MMAX 1001
using namespace std;

int peopleNum;
int hobbyGroup[MMAX];
vector<int> hobbys[MMAX];

void init() {
    for(int i = 1; i < MMAX; i++) {
        hobbyGroup[i] = 0;
    }
}

int find(int hobby) {
    if(hobbyGroup[hobby] == hobby) {
        return hobby;
    }
    else if(hobbyGroup[hobby] == -1) return 0;
    return find(hobbyGroup[hobby]);
}

void merge(int h1, int h2) {
    if(hobbyGroup[h2] == 0) hobbyGroup[h2] = h2;
    int f1 = find(h1);
    int f2 = find(h2);
    hobbyGroup[f2] = f1;
}

int main() {
    init();
    cin >> peopleNum;
    for(int people = 1; people <= peopleNum; people++) {
        int hobbySum;
        cin >> hobbySum;
        cin.get();
        int h1;
        if(hobbySum > 0) {
            cin >> h1;
            hobbys[people].push_back(h1);
            if(hobbyGroup[h1] == 0) hobbyGroup[h1] = h1;
            for(int hobby = 2; hobby <= hobbySum; hobby++) {
                int h2;
                cin >> h2;
                hobbys[people].push_back(h2);
                merge(h1, h2);
            }
        }
    }
    set<int> sum;
    for(int i = 1; i < MMAX; i++) {
        int f = find(i);
        if(f) sum.insert(f);
    }
    cout << sum.size() << endl;
    map<int, int> counter;
    for(int i = 1; i <= peopleNum; i++) {
        set<int> visit;
        for(auto h: hobbys[i]) {
            int f = find(h);
            if(visit.count(f)) continue;
            visit.insert(f);
            counter[f]++;
        }
    }
    map<int, int> count;
    for(auto c: counter) {
        count[c.second]++;
    }
    map<int, int>::reverse_iterator it = count.rbegin();
    map<int, int>::reverse_iterator end = count.rend();
    bool flag = true;
    for(; it != end; it++) {
        for(int i = 0; i < it->second; i++) {
            if(flag) flag = false;
            else cout << " ";
            cout << it->first;
        }
    }
}