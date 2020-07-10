#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#define MMAX 501
using namespace std;

typedef struct {
    unordered_map<int, int> to;
    int cycleNum;
    int shortRoad;
    bool isConfirmed;
    bool isVisited;
} Station;

Station stations[MMAX];
int maxCapacity, stationNum, target, roadNum;

void add_station(int id, int cycleNum) {
    stations[id].cycleNum = cycleNum;
    stations[id].shortRoad = 10000000;
    stations[id].isConfirmed = false;
    stations[id].isVisited = false;
}

void link_station(int s1, int s2, int cost) {
    stations[s1].to[s2] = cost;
    stations[s2].to[s1] = cost;
}

void short_cut(int current) {
    vector<int> toVisit;
    stations[current].shortRoad = 0;
    stations[current].isConfirmed = true;
    toVisit.push_back(current);
    while(toVisit.size() != (stationNum + 1)) {
        int min = 1000000;
        for(auto station: toVisit) {
            for(auto l: stations[station].to) {
                if(!stations[l.first].isConfirmed && stations[station].shortRoad + l.second < min) {
                    min = stations[station].shortRoad + l.second;
                }
            }
        }
        for(auto station: toVisit) {
            for(auto l: stations[station].to) {
                if(!stations[l.first].isConfirmed && stations[station].shortRoad + l.second == min) {
                    stations[l.first].shortRoad = min;
                    stations[l.first].isConfirmed = true;
                    toVisit.push_back(l.first);
                }
            }
        }
    }
}


vector<int> path;
vector<int> finalPath;
int need = 0;
int back = 0;
int finalMin = -100000;
int finalMax = 100000;

void search(int current) {
    // for(auto s: path) {
    //     cout << s << " -> ";
    // }
    // cout << endl;
    for(auto l: stations[current].to) {
        if(!stations[l.first].isVisited && path.back() != target) {
            if(stations[current].shortRoad + l.second == stations[l.first].shortRoad) {
                int im = need;
                int ia = back;
                // cout << "---------------" << l.first << " " << stations[l.first].cycleNum << endl;
                // cout << need << " " << back << endl;
                if(stations[l.first].cycleNum > 0) {
                    back += stations[l.first].cycleNum;
                }
                else {
                    int k = stations[l.first].cycleNum + back;
                    back = max(0, k);
                    need += min(0, k);
                }
                // cout << need << " " << back << endl;
                // cout << "---------------" << endl;
                path.push_back(l.first);
                search(l.first);
                need = im;
                back = ia;
                path.pop_back();
            }
        }
        else if(path.back() == target) {
            // cout << need << " " << back << endl;
            if(finalMin < need) {
                finalPath = path;
                finalMin = need;
                finalMax = back;
            }
            else if(back < finalMax && finalMin == need) {
                finalPath = path;
                finalMax = back;
            }
        }
    }
}

int main() {
    cin >> maxCapacity >> stationNum >> target >> roadNum;
    for(int station = 1; station <= stationNum; station++) {
        int cycleNum;
        cin >> cycleNum;
        add_station(station, cycleNum - maxCapacity / 2);
    }
    for(int road = 0; road < roadNum; road++) {
        int s1, s2, cost;
        cin >> s1 >> s2 >> cost;
        link_station(s1, s2, cost);
    }
    add_station(0, 0);
    short_cut(0);
    // for(int station = 1; station <= stationNum; station++) {
    //     cout << station << " shortest is " << stations[station].shortRoad << endl;
    // }
    path.push_back(0);
    search(0);
    //  for(int station = 1; station <= stationNum; station++) {
    //     cout << station << " max is " << stations[station].max << endl;
    // }
    cout << max(0, 0 - finalMin) << " ";
    for(int i = 0; i < finalPath.size(); i++) {
        if(i) cout << "->";
        cout << finalPath[i];
    }
    cout << " " << max(0, finalMax);
    return 0;
}

