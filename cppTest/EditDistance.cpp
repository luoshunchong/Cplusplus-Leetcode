#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
    for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
    for (int i = 1; i <= word1.size(); i++) {
        for (int j = 1; j <= word2.size(); j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }
    return dp[word1.size()][word2.size()];
}

// 0 代表啥都不做
// 1 代表插入
// 2 代表删除
// 3 代表替换

void printPath(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
    for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
    for (int i = 1; i <= word1.size(); i++) {
        for (int j = 1; j <= word2.size(); j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }
    //打印dp数组
    cout << "------------------dp数组----------------" << endl;
    for (auto d : dp) {
        for (auto a : d) {
            cout << a << " ";
        }
        cout << endl;
    }
    cout << "需要的最小编辑距离：" << dp[word1.size()][word2.size()] << endl;
    //开始反推
    cout << "------------------反推过程----------------" << endl;
    int i = word1.size(), j = word2.size();
    while (i > 0 && j > 0) {

        if (dp[i][j - 1] + 1 == dp[i][j]) { 
            cout << "word1 插入：" << word2[j - 1] << "代价：1" << endl;
            j--;
        }
        else if (dp[i - 1][j] + 1 == dp[i][j]) {
            cout << "word1 删除：" << word1[i - 1] << "代价：1" << endl;
            i--;
        }
        else if (dp[i - 1][j - 1] + 1 == dp[i][j]) {
            cout << "word1 :" << word1[i - 1] << "替换, word2：" << word2[j - 1] << "代价：1" << endl;
            i--;
            j--;
        }
        else if (dp[i - 1][j - 1] == dp[i][j]) {
            cout << "word1 :" << word1[i - 1] << "匹配, word2：" << word2[j - 1] << "代价：0" << endl;
            i--;
            j--;
        }
    }
    if (i > 0) {
        cout << "word1余下的所有字符删除，代价：" << i << endl;
    }
    if (j > 0) {
        cout << "word2余下的所有字符插入，代价：" << j << endl;
    }
}

int main() {
    string s1 = "rad";
    string s2 = "apple";
    // int res = minDistance(s1, s2);
    // cout << res << endl;

    printPath(s1, s2);
    return 0;
}