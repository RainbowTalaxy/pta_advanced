#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;

int main() {
    int studentNum, courseNum;
    cin >> studentNum >> courseNum;
    map<string, set<int>> infos;
    for (int course = 0; course < courseNum; course += 1) {
        int id, n;
        cin >> id >> n;
        for (int i = 0; i < n; i += 1) {
            string name;
            cin >> name;
            infos[name].insert(id);
        }
    }
    for (int student = 0; student < studentNum; student += 1) {
        string name;
        cin >> name;
        cout << name << " " << infos[name].size();
        for (auto c: infos[name]) {
            cout << " " << c;
        }
        cout << endl;
    }
}
