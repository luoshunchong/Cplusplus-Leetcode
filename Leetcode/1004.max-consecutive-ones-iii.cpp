// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1004.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //滑动窗口
        int left = 0, right = 0;
        int res = 0, zero = 0;
        while (right < nums.size()) {
            int c = nums[right];
            right++;
            if (c == 0) zero++;
            while (zero > k) {
                int t = nums[left];
                left++;
                if (t == 0) zero--;
                res = max(res, right - left);
            }
        }
        return max(res, right - left);
    }
};
// @lc code=end

