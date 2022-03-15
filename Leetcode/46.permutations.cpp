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
    // vector<vector<int>> permute(vector<int> &nums)
    // {
    //     vector<vector<int>> ans;
    //     backtracking(nums, 0, ans);
    //     return ans;
    // }
    // void backtracking(vector<int> &nums, int level, vector<vector<int>> &ans)
    // {
    //     if (level == nums.size() - 1)
    //     {
    //         ans.push_back(nums);
    //         return;
    //     }
    //     for (int i = level; i < nums.size(); ++i)
    //     {
    //         swap(nums[i], nums[level]);
    //         backtracking(nums, level + 1, ans);
    //         swap(nums[i], nums[level]);
    //     }
    // }

    vector<vector<int>> res;
    vector<int> ve;
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
    void backtracking(vector<int> &nums, vector<bool>& used)
    {
        if(ve.size()==nums.size()){
            res.push_back(ve);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if (used[i] == true)
                continue; // path里已经收录的元素，直接跳过
            used[i] = true;
            ve.push_back(nums[i]);
            backtracking(nums, used);
            used[i] = false;
            ve.pop_back();
        }
    }
};
// @lc code=end
