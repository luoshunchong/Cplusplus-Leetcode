/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 1; j < nums.size(); j++)
            {
                if ((i < j) && ((long long)nums[i] > (long long)2 * nums[j]))
                    res++;
            }
        }
        return res;
    }
};
// @lc code=end

