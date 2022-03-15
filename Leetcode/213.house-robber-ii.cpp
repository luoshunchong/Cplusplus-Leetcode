/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int res1 = robRange(nums, 0, nums.size()-2);//不考虑尾元素
        int res2 = robRange(nums, 1, nums.size()-1);//不考虑首元素
        return max(res1,res2);
    }
    int robRange(vector<int>& nums, int start, int end){
        if (start == end) return nums[start];
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for(int i=start + 2; i <= end; ++i){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};
// @lc code=end

