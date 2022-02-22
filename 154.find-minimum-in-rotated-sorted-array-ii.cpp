/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // int res = INT_MAX;
        // for (int i = 0; i < nums.size(); ++i) {
        //     if (res > nums[i]) res = nums[i];
        // }
        // return res;

        //使用二分法，使得时间复杂度为log(n)
        //使用左闭右开
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
            else right -= 1;
        }
        return nums[left];
    }
};
// @lc code=end

