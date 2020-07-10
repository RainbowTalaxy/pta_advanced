#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c = a + b;
    bool sign = true;
    if (c < 0) {
        sign = false;
        c *= -1;
    }
    stack<int> s;
    do {
        s.push(c % 1000);
        c /= 1000;
    } while (c != 0);
    int flag = 1;
    if (!sign) cout << "-";
    while (!s.empty()) {
        if(flag) {
            flag--;
            printf("%d", s.top());
        }
        else {
            printf(",%03d", s.top());
        }
        s.pop();
    }
    return 0;
}