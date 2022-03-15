/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        //使用二分法，使得时间复杂度为log(n)
        //使用左闭右开
        // if (nums.size() == 1) return nums[0];
        // int left = 0;
        // int right = nums.size() - 1;
        // int mid = 0;
        // while (nums[left] >= nums[right]) {
        //     if (right - left == 1) {
        //         mid = right;
        //         break;
        //     }
        //     mid = left + ((right - left) >> 1);
        //     if (nums[mid] > nums[left]) left = mid;
        //     else if (nums[mid] < nums[right]) right = mid;
        // }
        // return nums[mid];

        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
        }
        return nums[left];
    }
};
// @lc code=end

