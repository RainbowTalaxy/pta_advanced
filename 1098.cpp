#include<iostream>
#include<algorithm>
#define MMAXM 1000
using namespace std;

int compare(int a, int b) {
    return a < b;
}

void swap(int a[], int i, int j) {
    int t = a[i]; a[i] = a[j]; a[j] = t;
    // cout << "Yes\n";
}

void adjust(int a[], int root, int length) {
    if(length <= 0) return;
    int left = root * 2 + 1, right = root * 2 + 2, last;
    bool b1 = left < length;
    bool b2 = right < length;
    if(b1 && b2) {
        if(a[left] >= a[right]) last = left;
        else last = right;
    }
    else if(b1 && !b2) last = left;
    else if(!b1 && b2) last = right;
    else return;
    if(a[last] > a[root]) {
        swap(a, last, root);
        adjust(a, last, length);
    }

}

int main() {
    int n, origin[MMAXM], mid[MMAXM];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> origin[i];
    for(int i = 0; i < n; i++) cin >> mid[i];
    int p = 1;
    while(p < n && mid[p] >= mid[p - 1]) p++;
    int q = p + 1;
    while(p < n && mid[p] == origin[p]) p++;
    if(p == n) {
        cout << "Insertion Sort" << endl;
        sort(mid, mid + q, compare);
    }
    else {
        cout << "Heap Sort" << endl;
        int i = n - 1;
        while(i > 0 && mid[i] >= mid[0]) i--;
        // cout << i << endl;
        swap(mid, 0, i);
        adjust(mid, 0, i);
        
    }
    for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << mid[i];
    }
}