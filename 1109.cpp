#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define MMAX 10000
using namespace std;

struct People
{
    string name;
    int height;
    People(string n, int h) {
        name = n;
        height = h;
    }
};

bool cmp(People p1, People p2) {
    if(p1.height == p2.height) {
        return p1.name > p2.name;
    }
    return p1.height < p2.height;
}

int sums[MMAX];
vector<People> peoples;

int main() {
    int n, k;
    cin >> n >> k;
    string name; int height;
    for(int i = 0; i < n; i++) {
        cin >> name >> height;
        peoples.push_back(People(name, height));
    }
    sort(peoples.begin(), peoples.end(), cmp);
    // for(auto person: peoples) {
    //     cout << person.name << " ";
    // }
    int m = n / k;
    for(int i = 1; i <= k; i++) {
        sums[i] = m;
    }
    sums[1] += (n - m * k);


    for(int i = 1; i <= k; i++) {
        if(i != 1) cout << endl;
        bool space = true;
        vector<People> queue[2];
        for(int j = 1; j <= sums[i]; j++) {
            queue[j % 2].push_back(peoples.back());
            peoples.pop_back();
        }
        vector<People>::reverse_iterator it = queue[0].rbegin();
        vector<People>::reverse_iterator end = queue[0].rend();
        for(;it != end; it++) {
            if(space) space = false;
            else cout << " ";
            cout << (*it).name;
        }
        for(auto p: queue[1]) {
            if(space) space = false;
            else cout << " ";
            cout << p.name;
        }
    }
    return 0;
}