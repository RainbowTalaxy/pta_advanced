#include<iostream>
#include<string>
#include<map>
#include<ctype.h>
using namespace std;

string week[7] = {
    "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

map<char, int> hour = {
    {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
    {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
    {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14},
    {'F', 15}, {'G', 16}, {'H', 17}, {'I', 18}, {'J', 19},
    {'K', 20}, {'L', 21},{'M', 22}, {'N', 23}
};

int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int count = 0;
    for (int i = 0; i < a.size() && i < b.size(); i += 1) {
        if (count == 0) {
            if (a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G') {
                count += 1;
                cout << week[a[i] - 'A'] << " ";
            }
        } else if (count == 1) {
            if (a[i] == b[i] && (isdigit(a[i]) || (a[i] >= 'A' && a[i] <= 'N'))) {
                count += 1;
                printf("%02d:", hour[a[i]]);
            }
        } else {
            break;
        }
    }
    for (int i = 0; i < c.size() && i < d.size(); i += 1) {
        if (c[i] == d[i] && isalpha(c[i])) {
            printf("%02d", i);
            break;
        }
    }
}