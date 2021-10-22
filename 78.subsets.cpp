// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem78.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> ve;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtracking(nums, 0);
        return res;
    }
    void backtracking(vector<int> &nums, int pos)
    {
        res.push_back(ve);
        if (pos >= nums.size())
        {
            return;
        }
        for (int i = pos; i < nums.size(); ++i)
        {
            ve.push_back(nums[i]);
            backtracking(nums, i + 1);
            ve.pop_back();
        }
    }
};
// @lc code=end
