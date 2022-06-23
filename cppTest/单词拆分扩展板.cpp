#include <iostream>
#include <vector>
#include <string>

using namespace std;

int wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 0; i < wordDict.size(); ++i) {  //遍历物品
        for (int j = s.size(); j >= wordDict[i].size(); --j) {  //遍历背包容量
            int len = wordDict[i].size();
            string temp = s.substr(j - len, len);
            if (temp == wordDict[i] && dp[j - len]) dp[j] = dp[j - len];
        }
    }
    return dp[s.size()];
}

int main() {
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};

    // string s = "leetcode";
    // vector<string> wordDict = {"leet", "code"};

    // string s = "catsandog";
    // vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    int res = wordBreak(s, wordDict);
    cout << res << endl;
    return 0;
}