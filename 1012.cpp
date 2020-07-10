#include<iostream>
#include<map>
#include<set>
using namespace std;

typedef struct {
    int scores[4];
} Student;

map<int, Student> students;
map<int, int> allScore[4];

void addScore(Student &student, int course, int score) {
    student.scores[course] = score;
    if(allScore[course].count(score) == 0)
        allScore[course][score] = 1;
    else allScore[course][score] ++; 
}

void addStudent(int id, int c, int m, int e) {
    Student student;
    addScore(student, 1, c);
    addScore(student, 2, m);
    addScore(student, 3, e);
    addScore(student, 0, (c + m + e) / 3);
    students[id] = student;
}

int findRankByCourse(int id, int course) {
    int score = students[id].scores[course];
    int cnt = 1;
    map<int, int>::reverse_iterator it = allScore[course].rbegin();
    map<int, int>::reverse_iterator end = allScore[course].rend();
    for(; it != end; it++) {
        if(score == it->first) return cnt;
        cnt += it->second;
    }
    return cnt;
}

int findMax(int a[]) {
    for(int i = 0; i < 4; i++) {
        int j;
        for(j = 0; j < 4; j++) {
            if(a[i] > a[j]) break;
        }
        if(j == 4) return i;
    }
    return 0;
}

void coutMax(int id) {
    int s[4];
    for(int i = 0; i < 4; i++) {
        s[i] = findRankByCourse(id, i);
    }
    int index = findMax(s);
    switch(index) {
        case 0: cout << s[index] << " A";  return;
        case 1: cout << s[index] << " C";  return;
        case 2: cout << s[index] << " M";  return;
        case 3: cout << s[index] << " E";  return;
    }
}

int main() {
    int numStudent, numCheck;
    cin >> numStudent >> numCheck;
    int id, c, m, e;
    for(int i = 0; i < numStudent; i++) {
        cin >> id >> c >> m >> e;
        addStudent(id, c, m, e);
    }
    for(int i = 0; i < numCheck; i++) {
        cin >> id;
        if(i) cout << endl;
        if(students.find(id) != students.end()) coutMax(id);
        else cout << "N/A";
    }
    return 0;
}