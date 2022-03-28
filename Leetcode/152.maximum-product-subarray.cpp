// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem152.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        dp[0][0] = nums[0]; // 表示最大的
        dp[0][1] = nums[0]; // 表示最小的
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i][0] = max({dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i], nums[i]});
            dp[i][1] = min({dp[i - 1][1] * nums[i], dp[i - 1][0] * nums[i], nums[i]});
            if (dp[i][0] > res) res = dp[i][0];
        }
        return res;
    }
// @lc code=end

