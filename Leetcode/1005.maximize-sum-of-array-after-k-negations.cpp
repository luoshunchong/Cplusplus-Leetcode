// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem1005.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
                int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                k = 0;
            }
            else if (nums[i] < 0 && k > 0) {
                sum += abs(nums[i]);
                k--;
            }
            else if (nums[i] > 0 && k > 0) {
                if (k&1) {
                    int temp = 0;
                    sum += nums[i];
                    if (i != 0) temp = min(abs(nums[i - 1]), nums[i]);
                    else temp = nums[i];
                    sum -= temp*2;
                    k = 0;
                }
                else{
                    k = 0;
                    sum += nums[i];
                }
            }
            else sum += nums[i];
        }
        if (k != 0) {
            if (k&1) {
                int temp = abs(nums[nums.size() - 1]);
                sum -= temp * 2;
            }
            else int i = 0;
        }
        return sum;
    }
};
// @lc code=end

