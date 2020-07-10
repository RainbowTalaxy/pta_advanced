#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int studentNum, courseNum;
    scanf("%d %d", &studentNum, &courseNum);
    vector<string> infos[2501];
    for (int i = 0; i < studentNum; i++) {
        string name;
        int n;
        cin >> name;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int course;
            scanf("%d", &course);
            infos[course].push_back(name);
        }
    }
    for (int i = 1; i <= courseNum; i++) {
        printf("%d %lu\n", i, infos[i].size());
        sort(infos[i].begin(), infos[i].end());
        for (auto c: infos[i]) {
            printf("%s\n", c.c_str());
        }
    }
}