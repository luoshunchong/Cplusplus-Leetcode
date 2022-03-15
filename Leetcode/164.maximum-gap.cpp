/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i <= nums.size(); i++)
        {
            nums[i] - nums[i - 1] > res ? res = nums[i] - nums[i - 1] : res = res;
        }
        return res;
    }
};
// @lc code=end

