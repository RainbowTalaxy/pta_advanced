#include<iostream>
#include<vector>
using namespace std;


typedef struct {
    bool isVisited;
    vector<int> to;
} City;


City citys[1000];


void init(int city, bool isvisited) {
    citys[city].isVisited = isvisited;
}


void initAll(int n) {
    for(int i = 1; i <= n; i++) {
        init(i, false);
    }
}


void linkCity(int acity, int bcity) {
    citys[acity].to.push_back(bcity);
    citys[bcity].to.push_back(acity);
}


void findLinkedCity(int city) {
    citys[city].isVisited = true;
    for(auto linkCity: citys[city].to) {
        if(!citys[linkCity].isVisited)
            findLinkedCity(linkCity);
    }
}


int main() {

    int cityNum, roadNum, checkNum;
    cin >> cityNum >> roadNum >> checkNum;

    for(int road = 0; road < roadNum; road++) {
        int aCity, bCity;
        cin >> aCity >> bCity;
        linkCity(aCity, bCity);
    }

    for(int check = 0; check < checkNum; check++) {
        int cityTocheck, count = 0;
        cin >> cityTocheck;
        initAll(cityNum);
        init(cityTocheck, true);
        for(int city = 1; city <= cityNum; city++) {
            if(!citys[city].isVisited) {
                count++;
                findLinkedCity(city);
            }
        }
        if(check) cout << endl;
        cout << count - 1;
    }

    return 0;
}