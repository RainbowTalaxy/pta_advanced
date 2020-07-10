#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main() {
    int n, startIndex;
    cin >> n >> startIndex;
    map<int, int> poToValue, valueToPo, poToNext;
    for (int i = 0; i < n; i += 1) {
        int position, value, nextIndex;
        cin >> position >> value >> nextIndex;
        poToValue[position] = value;
        valueToPo[value] = position;
        poToNext[position] = nextIndex;
    }
    vector<int> list;
    while (startIndex != -1) {
        list.push_back(poToValue[startIndex]);
        startIndex = poToNext[startIndex];
    }
    sort(list.begin(), list.end());
    printf("%lu ", list.size());
    for (auto value: list) {
        printf("%05d\n", valueToPo[value]);
        printf("%05d %d ", valueToPo[value], value);
    }
    cout << "-1";
}