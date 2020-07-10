/**inspired by DaiMorph
 * https://www.jianshu.com/p/02154109d298
 */

#include<iostream>
using namespace std;


int main() {
    int sum = 0;
    int n; cin >> n;
    int base = 1;
    while (n / base) {
        int m = (n / base) % 10;
        int left = (n / base) / 10;
        int right = n % base;
        if (m == 0) sum += left * base;
        else if (m == 1) sum += left * base + 1 + right;
        else sum += (left + 1) * base;
        base *= 10;
    }
    cout << sum;
    return 0;
}
