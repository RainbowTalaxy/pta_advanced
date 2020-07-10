#include<iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; i ++) cin >> p[i];
    int max = -1, l = 0, left = 0, right = n - 1, q_left = 0;
    for(int i = 0; i < n; i ++){
        l += p[i];
        if(l > max) {
            max = l;
            left = q_left;
            right = i;
        }
        else if(l < 0) {
            l = 0;
            q_left = i + 1;
        }
    }
    if(max == -1) max = 0;
    cout << max << " " << p[left] << " " << p[right];
    return 0;
}