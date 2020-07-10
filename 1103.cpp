#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int numRes[401];
int n, k, p, sizeRes, fmax;
vector<int> result;
vector<int> proceed;

int getSum(vector<int> v) {
    int s = 0;
    for(auto i: v) {
        s += i;
    }
    return s;
}

bool compare(vector<int> v1, vector<int> v2) {
    int s1 = getSum(v1);
    int s2 = getSum(v2);
    return s1 > s2;
}

void DFS(int size, int last, int sum) {
    if(sum > n || last < 0) return;
    if(last == 0 && sum == n) {
        if(compare(proceed, result)) {
            result = proceed;
        }
        return;
    }
    for(; size >= 1; size--) {
        proceed.push_back(size);
        DFS(size, last - 1, sum + numRes[size]);
        proceed.pop_back();
    }
}

int main() {
    cin >> n >> k >> p;
    fill(numRes, numRes + 401, 1);
    fmax = 0;
    bool flag = true;
    for(sizeRes = 2; ; sizeRes++) {
        for(int power = 1; power <= p; power++) {
            numRes[sizeRes] *= sizeRes;
            if(numRes[sizeRes] > n) {
                sizeRes -= 1;
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    DFS(sizeRes, k, 0);
    
    if(getSum(result)) {
        cout << n;
        cout << " = ";
        bool flag = true;
        for(auto r: result) {
            if(flag) flag = false;
            else cout << " + ";
            cout << r << "^" << p;
        }
    }
    else cout << "Impossible";
    return 0;
    
}