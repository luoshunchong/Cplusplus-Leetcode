// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem216.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution
{
public:
    // vector<vector<int>> res;
    // vector<int> ve; //存储临时数组
    // vector<vector<int>> combinationSum3(int k, int n)
    // {
    //     backtracking(1, 0, k, n);
    //     return res;
    // }
    // void backtracking(int pos, int sum, int k, int n)
    // {
    //     if (ve.size() == k)
    //     {
    //         if (sum == n)
    //             res.push_back(ve);
    //         return;
    //     }
    //     for (int i = pos; i < 10; ++i)
    //     {
    //         sum += i;
    //         ve.push_back(i);
    //         backtracking(i + 1, sum, k, n);
    //         ve.pop_back();
    //         sum -= i;
    //     }
    // }

    vector<vector<int>> res;
    vector<int> ve; //存储临时数组
    vector<vector<int>> combinationSum3(int k, int n)
    {//回溯法剪枝操作
        backtracking(1, 0, k, n);
        return res;
    }
    void backtracking(int pos, int sum, int k, int n)
    {
        if(sum>n){
            return ;
        }
        if (ve.size() == k)
        {
            if (sum == n)
                res.push_back(ve);
            return;
        }
        for (int i = pos; i < 10-(k-ve.size())+1; ++i)
        {
            sum += i;
            ve.push_back(i);
            backtracking(i + 1, sum, k, n);
            ve.pop_back();
            sum -= i;
        }
    }
};
// @lc code=end
