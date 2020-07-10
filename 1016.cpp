#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;

typedef struct {
    string originRecord;
    bool mark;
    int month, day, hour, minute;
} Record;

map<string, map<string, Record>> users;
int toll[24];   //cents / minute
int totalToll = 0;



void addRecord(string name, string time, string mark) {
    int month = stoi(time.substr(0, 2));
    int day = stoi(time.substr(3, 2));
    int hour = stoi(time.substr(6, 2));
    int minute = stoi(time.substr(9, 2));
    bool markB;
    if(mark == "on-line") markB = true;
    else markB = false;
    Record record = {time, markB, month, day, hour, minute};
    users[name][time] = record;
}



void printUserTitle(string name) {
    map<string, Record>::iterator head = users[name].begin();
    cout << name;
    printf(" %02d\n", head->second.month);
}



void printDayHrMin(Record record) {
    printf("%02d:%02d:%02d ", record.day, record.hour, record.minute);
}



int countMinute(Record r1, Record r2) {
    int minutes = 0;
    minutes = minutes + (60 - r1.minute) + r2.minute;
    minutes = minutes + ((24 - r1.hour - 1) + r2.hour) * 60;
    minutes = minutes + (r2.day - (r1.day + 1)) * 60 * 24;
    return minutes;
}



double countMoney(Record r1, Record r2) {
    int money = 0;
    money = money + (60 - r1.minute) * toll[r1.hour] + r2.minute * toll[r2.hour];
    for(int i = r1.hour + 1; i < 24; i++) {
        money = money + 60 * toll[i];
    }
    for(int i = 0; i < r2.hour; i++) {
        money = money + 60 * toll[i];
    }
    money = money + (r2.day - (r1.day + 1)) * 60 * totalToll;
    return money;
}



int main() {

    for(int hour = 0; hour <= 23; hour++) {
        cin >> toll[hour];
        totalToll += toll[hour];
    }

    int recordNum; cin >> recordNum;

    for(int record = 0; record < recordNum; record++) {
        string name, time, mark;
        cin >> name >> time >> mark;
        addRecord(name, time, mark);
    }

    for(auto user: users) {
        Record start, last;
        int totalMoney = 0;
        bool markOn = false, markOff = false, printflag = true;
        for(auto record: user.second) {
            // cout << record.first << endl;
            // cout << "---------------------------" << endl;
            if(!markOff && record.second.mark) {
                start = record.second;
                markOn = true;
            }
            else if(markOn && !markOff && !record.second.mark) {
                last = record.second;
                markOff = true;
            }
            if(markOn && markOff) {
                if(printflag) {
                    printUserTitle(user.first);
                    printflag = false;
                }
                printDayHrMin(start);
                printDayHrMin(last);
                int money = countMoney(start, last);
                printf("%d $%.2f", countMinute(start, last), money / 100.0);
                cout << endl;
                totalMoney += money;
                markOn = false;
                markOff = false;
            }
        }
        if(totalMoney) printf("Total amount: $%.2lf\n", totalMoney / 100.0);
    }
    return 0;
}
