#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

struct Person {
    string name;
    int age, worths;
    Person(string n, int a, int w) {
        name = n;
        age = a;
        worths = w;
    }
    bool operator <(const Person &p) const {
        if (worths == p.worths) {
            if (age == p.age) {
                return name < p.name;
            } else {
                return age < p.age;
            }
        } else {
            return worths > p.worths;
        }
    }
};

int main() {
    int pNum, qNum;
    cin >> pNum >> qNum;
    vector<Person> datas, infos;
    for (int i = 0; i < pNum; i += 1) {
        char name[10];
        int age, worths;
        scanf("%s %d %d", name, &age, &worths);
        datas.push_back(Person(string(name), age, worths));
    }
    int ageNum[201] = {0};
    sort(datas.begin(), datas.end());
    for (auto data: datas) {
        if (ageNum[data.age] < 100) {
            infos.push_back(data);
            ageNum[data.age] += 1;
        }
    }
    for (int i = 1; i <= qNum; i += 1) {
        int num, minn, maxn;
        scanf("%d %d %d", &num, &minn, &maxn);
        printf("Case #%d:\n", i);
        vector<Person> result;
        int cnt = 0;
        for (auto info: infos) {
            if (cnt < num) {
                if (info.age >= minn && info.age <= maxn) {
                    printf("%s %d %d\n", info.name.c_str(), info.age, info.worths);
                    cnt += 1;
                } 
            } else {
                break;
            }
        }
        if (cnt == 0) {
            printf("None\n");
        }
    }
}
