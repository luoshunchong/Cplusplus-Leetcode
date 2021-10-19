/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    /*
    本题的难点：
        如何在同一树层上面去重？
        使用bool型的used数组，来记录同一树枝上的元素是否使用过。
        如果candidates[i] == candidates[i - 1] 并且 used[i - 1] == false，
        就说明：前一个树枝，使用了candidates[i - 1]，也就是说同一树层使用过candidates[i - 1]。
    */
    vector<vector<int>> res;
    vector<int> ve;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(0, 0, candidates, target,used);
        return res;
    }
    void backtracking(int pos, int sum, vector<int> &candidates, int target, vector<bool> &used)
    {
        if (sum == target)
        {
            res.push_back(ve);
            return;
        }
        for (int i = pos; i < candidates.size() && sum + candidates[i] <= target; ++i)
        {
            // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            sum += candidates[i];
            ve.push_back(candidates[i]);
            used[i] = true;
            backtracking(i + 1, sum, candidates, target, used);
            used[i] = false;
            sum -= candidates[i];
            ve.pop_back();
        }
    }
};
// @lc code=end
