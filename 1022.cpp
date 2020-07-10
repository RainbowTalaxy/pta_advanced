#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;

map<string, set<string>> titles;
map<string, set<string>> authors;
map<string, set<string>> keywords;
map<string, set<string>> publishers;
map<string, set<string>> years;


vector<string> split(string s, char pattern) {
    vector<string> result;
    int right = s.find(pattern);
    while(right != -1) {
        result.push_back(s.substr(0, right));
        s = s.substr(right + 1);
        right = s.find(pattern);
    }
    result.push_back(s);
    return result;
}


void addBook(string id, string title, string author, string keyword, string publisher, string year) {
    titles[title].insert(id);
    authors[author].insert(id);
    publishers[publisher].insert(id);
    years[year].insert(id);
    vector<string> keys = split(keyword, ' ');
    for(auto key: keys) {
        keywords[key].insert(id);
    }
}




int main() {
    int bookNum;
    cin >> bookNum;
    cin.get();
    for(int book = 0; book < bookNum; book++) {
        string id, title, author, keyword, publisher, year;
        getline(cin, id);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keyword);
        getline(cin, publisher);
        getline(cin, year);
        addBook(id, title, author, keyword, publisher, year);
    }
    // for(auto key: titles) {
    //     cout << key.first;
    // }


    int queryNum;
    cin >> queryNum;
    cin.get();
    int catagory;
    for(int query = 0; query < queryNum; query++) {
        string all;
        getline(cin, all);
        string word = all.substr(3);
        switch(all[0]) {
            case '1': {
                cout << all << endl;
                if(titles[word].empty()) cout << "Not Found" << endl;
                else {
                    for(auto title: titles[word]) {
                        cout << title << endl;
                    }
                }
                break;
            }
            case '2': {
                cout << all << endl;
                if(authors[word].empty()) cout << "Not Found" << endl;
                else {
                    for(auto author: authors[word]) {
                        cout << author << endl;
                    }
                }
                break;
            }
            case '3': {
                cout << all << endl;
                if(keywords[word].empty()) cout << "Not Found" << endl;
                else {
                    for(auto keyword: keywords[word]) {
                        cout << keyword << endl;
                    }
                }
                break;
            }
            case '4': {
                cout << all << endl;
                if(publishers[word].empty()) cout << "Not Found" << endl;
                else {
                    for(auto publisher: publishers[word]) {
                        cout << publisher << endl;
                    }
                }
                break;
            }
            case '5': {
                cout << all << endl;
                if(years[word].empty()) cout << "Not Found" << endl;
                else {
                    for(auto year: years[word]) {
                        cout << year << endl;
                    }
                }
                break;
            }
        }
    }
    
    // string s;
    // cin.get();
    // getline(cin, s);
    // vector<string> result = split(s, ' ');
    // for(auto ss: result) {
    //     cout << ss;
    // }

}