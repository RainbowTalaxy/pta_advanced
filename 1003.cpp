#include<iostream>
#include<vector>
#define MAX 500
using namespace std;

typedef struct {
    vector<int> linkedCitys;
    int to[MAX];
    int teamNum;
    int shortestRoad;
    int maxAmount;
    int kindRoads;
    bool isConfirmed;
} City;

void add_city(City citys[], int name, int teamNum) {
    citys[name].teamNum = teamNum;
    citys[name].shortestRoad = 100000;
    citys[name].maxAmount = teamNum;
    citys[name].kindRoads = 0;
    citys[name].isConfirmed = false;
}

void link_city(City citys[], int c1, int c2, int roadLength) {
    citys[c1].to[c2] = citys[c2].to[c1] = roadLength;
    citys[c1].linkedCitys.push_back(c2);
    citys[c2].linkedCitys.push_back(c1);
}

void short_cut(City citys[], int current, int cityNum) {
    vector<int> cityToVisit;
    citys[current].shortestRoad = 0;
    citys[current].isConfirmed = true;
    cityNum--;
    cityToVisit.push_back(current);
    while(cityNum) {
        int min = 100000;
        for(auto city: cityToVisit) {
            for(auto linkcity: citys[city].linkedCitys) {
                if(!citys[linkcity].isConfirmed) {
                    if(citys[city].shortestRoad + citys[city].to[linkcity] < min)
                        min = citys[city].shortestRoad + citys[city].to[linkcity];
                }
            }
        }
        for(auto city: cityToVisit) {
            for(auto linkcity: citys[city].linkedCitys) {
                if(!citys[linkcity].isConfirmed) {
                    if(citys[city].shortestRoad + citys[city].to[linkcity] == min) {
                        citys[linkcity].shortestRoad = min;
                        citys[linkcity].isConfirmed = true;
                        // cout << linkcity << " is confirmed" << endl;
                        cityToVisit.push_back(linkcity);
                        cityNum--;
                    }
                }
            }
        }
    }
}

void DFS(City citys[], int current, int visit[]) {
    for(auto city: citys[current].linkedCitys) {
        if(!visit[city]) {
            if(citys[current].shortestRoad + citys[current].to[city] == citys[city].shortestRoad) {
                citys[city].kindRoads ++;
                if(citys[city].maxAmount < citys[current].maxAmount + citys[city].teamNum)
                    citys[city].maxAmount = citys[current].maxAmount + citys[city].teamNum;
                visit[current] = 1;
                // cout << current << endl;
                DFS(citys, city, visit);
                visit[current] = 0;
            }
        }
    }
    // cout << "loading" << endl;
}

int main() {
    int n, m, current, target;
    City citys[MAX];
    cin >> n >> m >> current >> target;
    for(int city = 0; city < n; city++) {
        int teamNum;
        cin >> teamNum;
        add_city(citys, city, teamNum);
    }
    for(int road = 0; road < m; road++) {
        int c1, c2, roadLength;
        cin >> c1 >> c2 >> roadLength;
        link_city(citys, c1, c2, roadLength);
    }
    short_cut(citys, current, n);
    int visit[MAX] = {0};
    citys[current].kindRoads = 1;
    DFS(citys, current, visit);
    cout << citys[target].kindRoads << " " << citys[target].maxAmount;
}