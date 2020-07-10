#include<iostream>
#include<string>
#include<queue>
using namespace std;

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    int leftMinutes;
    bool state;
    Time timeToLeave;
} Customer;

Time current = {8, 0};
Customer customers[1001];
queue<int> windows[20];
queue<int> waiting;
int windowNum, capacity;


Time addMinutes(Time time, int minutes) {
    time.hour += (minutes + time.minute) / 60;
    time.minute = (minutes + time.minute) % 60;
    return time;
}


void registerCustomer(int sequence, int time) {
    customers[sequence] = {time, false, {-1, -1}};
    waiting.push(sequence);
}


void pushCustomer() {
    int shortestLine;
    while(1) {
        if(waiting.size() == 0) return;
        shortestLine = capacity;
        for(int window = 0; window < windowNum; window++) {
            int length = windows[window].size();
            if(length < shortestLine) shortestLine = length;
        }
        if(shortestLine == capacity) return;
        for(int window = 0; window < windowNum; window++) {
            if(windows[window].size() == shortestLine) {
                if(!waiting.empty()) {
                    windows[window].push(waiting.front());
                    waiting.pop();
                }
            }
        }
        // cout << "loading" << endl;
    }
}

int popCustomer() {
    if(current.hour >= 17) {
        for(int window = 0; window < windowNum; window++) {
            if(!windows[window].empty()) {
                Customer  &c = customers[windows[window].front()];
                if(c.state) c.timeToLeave = addMinutes(current, c.leftMinutes);
            }
        }
        return 0;
    }
    // if(current.hour >= 17) return 0;
    int shortestTime = 100000;
    for(int window = 0; window < windowNum; window++) {
        if(!windows[window].empty()) {
            int time = customers[windows[window].front()].leftMinutes;
            if(time < shortestTime) shortestTime = time;
        }
    }
    if(shortestTime == 100000) return 0;
    current = addMinutes(current, shortestTime);
    for(int window = 0; window < windowNum; window++) {
        if(!windows[window].empty()) {
            if(customers[windows[window].front()].leftMinutes == shortestTime) {
                customers[windows[window].front()].timeToLeave = current;
                windows[window].pop();
                if(current.hour < 17) customers[windows[window].front()].state = true;
            }
            else {
                customers[windows[window].front()].leftMinutes -= shortestTime;
            }
        }
    }
    // cout << "loading" << endl;
    return 1;
}

string timeToString(Time  time) {
    if(time.hour == -1) return "Sorry";
    char format[10];
    sprintf(format, "%02d:%02d", time.hour, time.minute);
    string result = "";
    result.append(format);
    return result;
}


int main() {

    int customerNum, queryNum;
    cin >> windowNum >> capacity >> customerNum >> queryNum;

    for(int customer = 1; customer <= customerNum; customer++) {
        int time;
        cin >> time;
        registerCustomer(customer, time);
    }

    do {
        pushCustomer();
    } while(popCustomer());

    for(int query = 0; query < queryNum; query++) {
        int sequence;
        cin >> sequence;
        if(query) cout << endl;
        cout << timeToString(customers[sequence].timeToLeave);
    }
}