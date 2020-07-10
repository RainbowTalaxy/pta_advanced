#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

struct Student {
    string name;
    int scores[4] = {-1, -1, -1, -1};
};

map<string, Student> students;

bool cmp(Student a, Student b) {
    if (a.scores[3] == b.scores[3]) {
        return a.name < b.name;
    }
    return a.scores[3] > b.scores[3];
}

int main() {
    int sNum[3];
    cin >> sNum[0] >> sNum[1] >> sNum[2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < sNum[i]; j++) {
            string name;
            int score;
            cin >> name >> score;
            students[name].name = name;
            students[name].scores[i] = score;
        }
    }
    vector<Student> vs;
    for (auto s: students) {
        if (s.second.scores[0] < 200) continue;
        if (s.second.scores[1] < s.second.scores[2]) s.second.scores[3] = s.second.scores[2];
        else s.second.scores[3] = (s.second.scores[1] * 40 + s.second.scores[2] * 60 + 50) / 100;
        if (s.second.scores[3] < 60) continue;
        vs.push_back(s.second);
    }
    sort(vs.begin(), vs.end(), cmp);
    for (auto v: vs) {
        cout << v.name;
        for (int i = 0; i < 4; i++) cout << " " << v.scores[i];
        cout << endl;
    }
    return 0;
}