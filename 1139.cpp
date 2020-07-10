#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#define MMAX 10000
using namespace std;

struct Person {
    bool isMale = true;
    map<bool, set<int>> friends;
    void setSex(string id) {
        isMale = (id[0] != '-');
    }
    void addFriend(int p, bool sex) {
        friends[sex].insert(p);
    }
} people[MMAX];

struct Pair {
    int pa, pb;
    Pair(int a, int b) {
        pa = a;
        pb = b;
    }
};

int peopleNum, relationNum;

int convert(string i) {
    return abs(stoi(i));
}

void add_relation(string a, string b) {
    int ai = convert(a);
    int bi = convert(b);
    people[ai].setSex(a);
    people[bi].setSex(b);
    people[ai].addFriend(bi, people[bi].isMale);
    people[bi].addFriend(ai, people[ai].isMale);
}

vector<Pair> find(int a, int b) {
    vector<Pair> links;
    bool sexa = people[a].isMale;
    bool sexb = sexa;
    if (people[a].isMale != people[b].isMale) sexb = !sexb;
    for (auto pi: people[a].friends[sexa]) {
        if (pi == a || pi == b) continue;
        for (auto pj: people[pi].friends[sexb]) {
            if (pj == a || pj == b) continue;
            if (people[pj].friends[people[b].isMale].count(b)) links.push_back(Pair(pi, pj));
        }
    }
    return links;
}

int main() {
    cin >> peopleNum >> relationNum;
    for (int r = 0; r < relationNum; r++) {
        string a, b;
        cin >> a >> b;
        add_relation(a, b);
    }
    int queryNum;
    cin >> queryNum;
    for (int q = 0; q < queryNum; q++) {
        string a, b;
        vector<Pair> v;
        cin >> a >> b;
        v = find(convert(a), convert(b));
        cout << v.size() << endl;
        for (auto i: v) {
            printf("%04d %04d\n", i.pa, i.pb);
        }
    }
    return 0;
}