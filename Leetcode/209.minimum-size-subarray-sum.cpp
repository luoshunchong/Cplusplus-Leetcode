// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem209.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums) {
    //  //滑动窗口
    //     int res = INT32_MAX;
    //     int j = 0;   // 滑动窗口起始位置
    //     int sum = 0; // 滑动窗口数值之和
    //     int len = 0; // 滑动窗口的长度
    //     for (int i = 0; i < nums.size(); ++i)
    //     {
    //         sum += nums[i];
    //         while (sum >= target)
    //         {
    //             len = (i - j + 1); // 取子序列的长度
    //             res = res > len ? len : res;
    //             sum -= nums[j++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
    //         }
    //     }
    //     return res == INT32_MAX ? 0 : res;
    // }

        if (nums.size() == 1) {
            if (nums[0] == target) return 1;
            else return 0;
        }

        int res = INT_MAX;
        int left = 0;
        int right = 1;
        int sum = nums[left] + nums[right];
        while (right < nums.size()) {
            if (sum > target) {
                sum -= nums[left];
                left++;
            }
            else if (sum < target) {
                right++;
                if (right < nums.size())
                sum += nums[right];
            }
            else {
                res = min(res, (right - left + 1));
                right++;
                if (right < nums.size())
                sum += nums[right];
            }
        }
        return res == INT_MAX? 0 : res;
    }
};
// @lc code=end
