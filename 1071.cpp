#include<iostream>
#include<ctype.h>
#include<string>
#include<map>
using namespace std;

char handle(char letter) {
    if (isalpha(letter) || isdigit(letter)) return tolower(letter);
    else return ' ';
}

int main() {
    string sentence;
    getline(cin, sentence);
    string word = "";
    map<string, int> wordCount;
    for(auto letter: sentence) {
        char handled = handle(letter);
        if (handled != ' ') {
            word += handled;
        }
        else if (word != "") {
            wordCount[word]++;
            word = "";
        }
    }
    if (word != "") {
            wordCount[word]++;
            word = "";
        }
    int count = 0;
    for (auto word: wordCount) {
        if (word.second > count) count = word.second;
    }
    string result = "";
    for (auto word: wordCount) {
        if (word.second == count) {
            if (result == "" || result > word.first) {
                result = word.first;
            }
        }
    }
    cout << result << " " << count;
}