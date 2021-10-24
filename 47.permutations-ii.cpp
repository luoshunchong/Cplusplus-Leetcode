/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> ve;
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); //进行排序
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        if (ve.size() == nums.size())
        {
            res.push_back(ve);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            {
                continue;
            }
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
