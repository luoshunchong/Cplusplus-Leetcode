// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem77.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> temp(k, 0);
        int count = 0;
        backtracking(ans, temp, count, 1, n, k);
        return ans;
    }
    void backtracking(vector<vector<int>> &ans, vector<int> &temp, int count, int pos, int n, int k)
    {
        if (count == k)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = pos; i <= n; ++i)
        {
            temp[count++] = i;                           //修改当前状态
            backtracking(ans, temp, count, i + 1, n, k); //递归子节点
            --count;                                     //回改当前节点状态
        }
    }
};
// @lc code=end
