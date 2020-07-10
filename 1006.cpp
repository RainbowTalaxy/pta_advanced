#include<iostream>
#include<string>
#define MAXNUM 10000
using namespace std;

typedef struct {
    string id;
    string sign_in_time;
    string sign_out_time;
} Record;

int main() {
    int n;
    Record records[MAXNUM];
    cin >> n;
    for(int record = 0; record < n; record ++) {
        cin >> records[record].id;
        cin >> records[record].sign_in_time;
        cin >> records[record].sign_out_time;
    }
    string max = "00:00:00";
    string min = "24:60:61";
    int maxs_record;
    int mins_record;
    for(int record = 0; record < n; record ++) {
        if(records[record].sign_in_time < min) {
            mins_record = record;
            min = records[record].sign_in_time;
        }
        if(records[record].sign_out_time > max) {
            maxs_record = record;
            max = records[record].sign_out_time;
        }
    }
    cout << records[mins_record].id << " " <<records[maxs_record].id;
}