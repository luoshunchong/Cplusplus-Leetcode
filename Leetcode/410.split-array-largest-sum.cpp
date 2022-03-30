// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem410.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        //求数组的和,数组中最大的值
        int sum = 0, maxNum = INT_MIN;
        for (auto a : nums) {
            sum += a;
            if (maxNum < a) maxNum = a;
        }
        int left = maxNum, right = sum;
        while (left < right) { //左闭右开
            int mid = left + ((right - left) >> 1);
            if (check(mid, nums, m)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
    //基于贪心的策略
    bool check(int mid, vector<int>& nums, int m) {
        int total = 0, cur = 1;
        for (auto a : nums) {
            if ((total + a) > mid) {
                cur++;
                total = a;
            }
            else {
                total += a;
            }
        }
        return cur <= m;
    }
};
// @lc code=end

