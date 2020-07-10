#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct User {
    int id, sum;
    int perfectSum;
    vector<int> scores;
    vector<bool> compileStates;

    User(int i, int size) {
        id = i;
        sum = 0;
        scores.resize(size);
        compileStates.resize(size);
        for (int j = 0; j < size; j += 1) {
            scores[j] = -1;
            compileStates[j] = false;
        }
    }

    bool operator <(const User &user) const {
        if (sum == user.sum) {
            if (perfectSum == user.perfectSum) {
                return id < user.id; 
            } else {
                return perfectSum > user.perfectSum;
            }
        } else {
            return sum > user.sum;
        }
    }

    void update(int problemId, int score, int perfectScore) {
        if (score == -1) {
            score = 0;
        } else {
            compileStates[problemId] = true;
        }
        if (scores[problemId] < score) {
            if (scores[problemId] != -1) {
                sum -= scores[problemId];
            }
            sum += score;
            if (score == perfectScore) {
                perfectSum += 1;
            }
            scores[problemId] = score;
        }
    }

    bool valid() {
        for (int i = 0; i < scores.size(); i += 1) {
            if (scores[i] != -1 && compileStates[i]) {
                return true;
            }
        }
        return false;
    }

    void printInfo() {
        printf(" %05d %d", id, sum);
        for (auto score: scores) {
            score == -1 ? printf(" -") : printf(" %d", score);
        }
    }
};

int main() {
    int userNum, problemNum, submissionNum;
    cin >> userNum >> problemNum >> submissionNum;
    vector<User> users;
    vector<int> problemScores;
    for (int i = 0; i < userNum; i += 1) {
        users.push_back(User(i + 1, problemNum));
    }
    for (int i = 0; i < problemNum; i += 1) {
        int score;
        cin >> score;
        problemScores.push_back(score);
    }
    for (int i = 0; i < submissionNum; i += 1) {
        int userId, problemId, score;
        cin >> userId >> problemId >> score;
        users[userId - 1].update(problemId - 1, score, problemScores[problemId - 1]);
    }
    vector<User> validUsers;
    for (auto user: users) {
        if (user.valid()) {
            validUsers.push_back(user);
        }
    }
    sort(validUsers.begin(), validUsers.end());
    int rank = 0, count = 1;
    int preSum = -1;
    for (auto user: validUsers) {
        if (preSum != user.sum) {
            rank += count;
            count = 1;
        } else {
            count += 1;
        }
        printf("%d", rank);
        user.printInfo();
        printf("\n");
        preSum = user.sum;
    }
    return 0;
}