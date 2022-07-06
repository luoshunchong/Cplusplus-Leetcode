// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] ����֮��
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        for (i = 0; i < nums.size() - 1; i++)
        {
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {i, j};
    }
};
// @lc code=end

