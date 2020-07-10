#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;

typedef struct {
    int rank[2];
    int location;
} Rank;

map<int, set<string>> allScores;
map<string, Rank> theRank;

void freshRank(map<int, set<string>> list, int kind) {
    int counter = 0;
    int rank = 1;
    map<int, set<string>>::reverse_iterator score = list.rbegin();
    map<int, set<string>>::reverse_iterator end = list.rend();
    for(; score != end; score++) {
        for(auto id: score->second) {
            counter++;
            theRank[id].rank[kind] = rank;
        }
        rank += counter;
        counter = 0;
    }
}


int main() {
    int listNum;
    cin >> listNum;
    for(int list = 1; list <= listNum; list++) {
        map<int, set<string>> scores;
        int locNum;
        cin >> locNum;
        for(int location = 0; location < locNum; location++) {
            string id;
            int score;
            cin >> id >> score;
            scores[score].insert(id);
            allScores[score].insert(id);
            theRank[id].location = list;
        }
        freshRank(scores, 1);
    }
    freshRank(allScores, 0);
    map<int, set<string>>::reverse_iterator score = allScores.rbegin();
    map<int, set<string>>::reverse_iterator end = allScores.rend();
    int count = 0;
    for(auto score: allScores) {
        for(auto id: score.second) {
            count++;
        }
    }
    cout << count << endl;
    // bool flag = true;
    for(; score != end; score++) {
        for(auto id: score->second) {
            // if(flag) flag = false;
            // else cout << endl;
            cout << id << " ";
            cout << theRank[id].rank[0] << " ";
            cout << theRank[id].location << " ";
            cout << theRank[id].rank[1] << endl;
        }
    }
    return 0;
}