// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem32.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        //动态规划
        if (s.size() <= 1) return 0;
        vector<int> dp(s.size());
        int res = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '(') dp[i] = 0;
            else {
                if (s[i - 1] == '(') dp[i] = (i - 2) >= 0 ? dp[i - 2] + 2 : 2;
                else {
                    if ((i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                    }
                }
            }
            res = max(res, dp[i]);
        } 
        return res;
    }
};
// @lc code=end

