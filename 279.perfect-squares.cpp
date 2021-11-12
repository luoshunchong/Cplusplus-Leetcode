/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    // int numSquares(int n) {
    //     int temp = sqrt(n);
    //     vector<int> m;
    //     for (int i = 1; i <= temp; ++i) {
    //         m.push_back(i * i);
    //     }
    //     vector<int> dp(n+1, INT_MAX);
    //     dp[0] = 0;
    //     for (int i = 0; i < m.size(); ++i) {
    //         for (int j = m[i]; j <= n; ++j) {
    //             if (dp[j-m[i]] != INT_MAX) {
    //                 dp[j] = min(dp[j], dp[j-m[i]] + 1);
    //             }
    //         }
    //     }
    //     if (dp[n] == INT_MAX) return 0;
    //     return dp[n];
    // }

    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

