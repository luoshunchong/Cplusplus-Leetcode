/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    // //动态规划
    // int findLengthOfLCIS(vector<int>& nums) {
    //     if (nums.size() <= 1) return nums.size();
    //     vector<int> dp(nums.size(), 1);
    //     int res = 1;//记录最大的长度的dp数组的位置
    //     for (int i = 0; i < nums.size() - 1; ++i) {
    //         if (nums[i + 1] > nums[i]) dp[i + 1] = dp[i] + 1;
    //         if (res < dp[i + 1]) res = dp[i + 1];
    //     }
    //     return res;
    // }

    //贪心
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int count = 1;
        int res = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] > nums[i]) count++;
            else count = 1;
            res = max(res, count);
        }
        return res;
    }
};
// @lc code=end

