//inspired by niunuo

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
    int arriveTime, proceedTime;
} Customer;

bool compare(Customer a, Customer b) {
    return a.arriveTime < b.arriveTime;
}

int main() {
    int customerNum, windowNum;
    cin >> customerNum >> windowNum;
    vector<Customer> customers;
    for(int customer = 0; customer < customerNum; customer++) {
        int hour, minute, second, proceed;
        scanf("%d:%d:%d %d", &hour, &minute, &second, &proceed);
        int arriveTime = hour * 3600 + minute * 60 + second;
        int proceedTime = proceed * 60;
        if(arriveTime > 61200) continue;
        Customer c = {arriveTime, proceedTime};
        customers.push_back(c);
    }

    sort(customers.begin(), customers.end(), compare);
    
    double result = 0;
    vector<int> windows(windowNum, 28800);
    for(auto customer: customers) {
        int winNo = 0, quickFinish = windows[0];
        for(int window = 1; window < windowNum; window++) {
            if(windows[window] < quickFinish) {
                quickFinish = windows[window];
                winNo = window;
            }
        }
        if(windows[winNo] <= customer.arriveTime) {
            windows[winNo] = customer.arriveTime + customer.proceedTime;
        }
        else {
            result += (windows[winNo] - customer.arriveTime);
            windows[winNo] += customer.proceedTime;
        }
    }
    if(customers.size() == 0) cout << "0.0";
    else printf("%.1f", result / 60 / customers.size());

    // for(auto i: customers) {
    //     cout << i.arriveTime << endl;
    // }



}