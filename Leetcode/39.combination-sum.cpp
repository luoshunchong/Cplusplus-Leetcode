// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem39.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> ve;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        if (candidates.size() == 0)
            return {};
        backtracking(0, 0, target, candidates);
        return res;
    }
    void backtracking(int pos, int sum, int target, vector<int> &candidates)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(ve);
            return;
        }
        for (int i = pos; i < candidates.size(); ++i)
        {
            sum += candidates[i];
            ve.push_back(candidates[i]);
            backtracking(i, sum, target, candidates);
            sum -= candidates[i];
            ve.pop_back();
        }
    }
    //可以对candidates排序一下，然后在循环的时候判断一下sum+candidates[i]<target?,进行优化
    //但是要考虑一下排序的消耗
};
// @lc code=end
