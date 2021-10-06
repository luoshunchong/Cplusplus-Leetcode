/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp, pre;
        for (int i = 0; i < k; ++i)
        {
            pre = nums[nums.size() - 1];
            for (int j = 0; j < nums.size(); ++j)
            {
                temp = nums[j];
                nums[j] = pre;
                pre = temp;
            }
        }
    }
};
// @lc code=end

