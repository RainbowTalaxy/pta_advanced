#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main() {
    int colorNum, favorNum, stripNum, color;
    cin >> colorNum >> favorNum;
    map<int, int> mapFavor;
    vector<int> LIS;
    for(int favor = 1; favor <= favorNum; favor++) {
        cin >> color;
        mapFavor[color] = favor;
    }
    LIS.push_back(0);
    cin >> stripNum;
    for(int strip = 1; strip <= stripNum; strip++) {
        cin >> color;
        if(mapFavor.count(color) == 0) continue;
        int seq = mapFavor[color];
        if(seq >= LIS.back()) LIS.push_back(seq);
        else {
            * upper_bound(LIS.begin(), LIS.end(), seq) = seq;
        }
        // for(auto l: LIS) {
        // cout << l << " ";
        // }
        // cout << endl;
    }
    cout << LIS.size() - 1;
    return 0;
}