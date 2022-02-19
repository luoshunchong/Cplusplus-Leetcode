// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem53.h"

using namespace std;
// @before-stub-for-debug-end

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
    //从左到右遍历，相加，如果sum小于0，重新开始找字串
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int sum = nums[0];
        int max = sum;
        for (int i = 1; i < nums.size(); i++) {
            if (sum < 0) {
                sum = nums[i];
            }
            else {
                sum += nums[i];
            }
            
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};
// @lc code=end

