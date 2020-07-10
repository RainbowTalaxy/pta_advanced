#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int pointer, size, K;
    cin >> pointer >> size >> K;
    int values[100000] = {0};
    int nexts[100000] = {0};
    for (int i = 0; i < size; i += 1) {
        int addr, value, next;
        cin >> addr >> value >> next;
        values[addr] = value;
        nexts[addr] = next;
    }
    vector<int> list;
    bool flag = true;
    while (pointer != -1)
    {
        list.push_back(pointer);
        if (list.size() == K) {
            reverse(list.begin(), list.end());
            for (auto e : list) {
                flag ? flag = false : printf("%05d\n", e);
                printf("%05d %d ", e, values[e]);
            }
            list.clear();
        }
        pointer = nexts[pointer];
    }
    for (auto e : list) {
        if (flag) {
            flag = false;
        } else {
            printf("%05d\n", e);
        }
        printf("%05d %d ", e, values[e]);
    }
    cout << -1;
    return 0;
}
