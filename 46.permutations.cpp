// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem46.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        backtracking(nums, 0, ans);
        return ans;
    }
    void backtracking(vector<int> &nums, int level, vector<vector<int>> &ans)
    {
        if (level == nums.size() - 1)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); ++i)
        {
            swap(nums[i], nums[level]);
            backtracking(nums, level + 1, ans);
            swap(nums[i], nums[level]);
        }
    }
};
// @lc code=end
