// @algorithm @lc id=139 lang=cpp 
// @title word-break


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "algm/algm.h"
using namespace std;
// @test("leetcode",["leet","code"])=true
// @test("applepenapple",["apple","pen"])=true
// @test("catsandog",["cats","dog","sand","and","cat"])=false
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) { //遍历背包容量
            for (int j = 0; j < i; ++j) { //遍历物品
                string word = s.substr(j, i - j);
                if (wordset.find(word) != wordset.end() && dp[j]){
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};