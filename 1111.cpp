#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


struct Link {
    int city, lx[2];
    Link(int c, int l, int t) {
        city = c;
        lx[0] = l;
        lx[1] = t;
    }
};

struct City {
    vector<Link> links;
    bool isConfirmed = false;
    int ex[2] = {0, 0};
    bool dx[2] = {false, false};
};

vector<City> citys;
int cityNum, roadNum;

void link_city(int from, int to, int length, int time) {
    citys[from].links.push_back(Link(to, length, time));
}

void add_road(int a, int b, int oneWay, int length, int time) {
    link_city(a, b, length, time);
    if (!oneWay) link_city(b, a, length, time);
}

void init_all() {
    for (int i = 0; i < cityNum; i++) {
        citys[i].isConfirmed = false;
    }
}

void toEx(int source, int destination, int para) {
    vector<City> toVisit;
    citys[source].ex[para] = 0;
    citys[source].isConfirmed = true;
    toVisit.push_back(citys[source]);
    while(toVisit.size() != cityNum) {
        int min = 100000000;
        for (auto current: toVisit) {
            for (auto link: current.links) {
                if (!citys[link.city].isConfirmed) {
                    int k = current.ex[para] + link.lx[para];
                    if (k < min) min = k;
                }
            }
        }
        bool flag = false;
        for (auto current: toVisit) {
            if (flag) break;
            for (auto link: current.links) {
                if (!citys[link.city].isConfirmed) {
                    int k = current.ex[para] + link.lx[para];
                    if (k == min) {
                        citys[link.city].ex[para] = k;
                        citys[link.city].isConfirmed = true;
                        toVisit.push_back(citys[link.city]);
                        flag = true;
                        break;
                    }
                }
            }
        }
    }
}

int mx[2] = {10000, 10000};
void findDFS(int source, int target, int para, int sum) {
    if (source == target && sum < mx[para]) mx[para] = sum;
    else {
        for (auto link: citys[source].links) {
            int k = citys[source].ex[para] + link.lx[para];
            if (k == citys[link.city].ex[para])
                findDFS(link.city, target, para, sum + 1);
        }
    }
}

vector<int> vr[2];
bool DFS(int source, int target, int para, int sum) {
    if (source == target && sum == mx[para]) {
        vr[para].push_back(source);
        return true;
    }
    else {
        for (auto link: citys[source].links) {
            int k = citys[source].ex[para] + link.lx[para];
            if (k != citys[link.city].ex[para]) continue;
            if(DFS(link.city, target, para, sum + 1)) {
                vr[para].push_back(source);
                return true;
            }
            else vr[para].clear();
        }
    }
    return false;
}

int main() {
    cin >> cityNum >> roadNum;
    for(int city = 0; city < cityNum; city++) citys.push_back(City());
    for (int road = 0; road < roadNum; road++) {
        int a, b, f, l, t;
        cin >> a >> b >> f >> l >> t;
        add_road(a, b, f, l, t);
    }
    int source, target;
    cin >> source >> target;
    string desx[2] = {"Distance = ", "Time = "};
    for (int i = 0; i < 2; i++) {
        init_all();
        toEx(source, target, i);
        findDFS(source, target, i, 0);
        DFS(source, target, i, 0);
        reverse(vr[i].begin(), vr[i].end());
    }
    if(vr[0] == vr[1]) {
        cout << desx[0] << citys[target].ex[0] << "; ";
        cout << desx[1] << citys[target].ex[1];
        bool f = true;
        for (auto v: vr[1]) {
            if (f) {
                cout << ": ";
                f = false;
            }
            else cout << " -> ";
            cout << v;
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < 2; i++) {
            cout << desx[i] << citys[target].ex[i];
            bool f = true;
            for (auto v: vr[i]) {
                if (f) {
                    cout << ": ";
                    f = false;
                }
                else cout << " -> ";
                cout << v;
            }
        cout << endl;
        }
    }
    return 0;
}