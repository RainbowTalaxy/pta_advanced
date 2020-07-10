#include<iostream>
using namespace std;

int addTime(int start, int target) {
    if(start > target) {
        return 4 * (start - target) + 5;
    }
    else if (start < target) {
        return 6 * (target - start) + 5;
    }
    else return 0;
}

int main() {
    int n, current = 0, target, time = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> target;
        time += addTime(current, target);
        current = target;
    }
    cout << time;
    return 0;

}