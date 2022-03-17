// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem221.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int res = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            dp[i][0] = matrix[i][0] - '0';
            res = max(res, dp[i][0]);
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            dp[0][i] = matrix[0][i] - '0';
            res = max(res, dp[0][i]);
        }
        
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if ((matrix[i][j] - '0') == 0) dp[i][j] = 0;
                else {
                    if (dp[i - 1][j] && dp[i - 1][j - 1] && dp[i][j - 1]) {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
                    }
                    else dp[i][j] = 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
// @lc code=end

