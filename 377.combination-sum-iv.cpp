/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        //求排列，先遍历背包再遍历物品
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; ++j)
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                if (j - nums[i] >= 0 && dp[j] < INT_MAX - dp[j - nums[i]])
                    dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
// @lc code=end
