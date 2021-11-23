/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    // //动态规划
    // int maxSubArray(vector<int>& nums) {
    //     if (nums.size() == 0) return 0;
    //     vector<int> dp(nums.size(), 0);
    //     dp[0] = nums[0];
    //     int res = nums[0];
    //     for (int i = 1; i < nums.size(); ++i) {
    //         dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    //         res = max(res, dp[i]);
    //     }
    //     return res;
    // }

    //贪心算法
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
    }
};
// @lc code=end

