// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include "commoncppproblem90.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{
public:
    // vector<vector<int>> res;
    // vector<int> ve;
    // vector<vector<int>> subsetsWithDup(vector<int> &nums)
    // {//注意回溯过程中要进行树层去重
    //     vector<bool> used(nums.size(), false);
    //     sort(nums.begin(), nums.end());
    //     backtracking(nums, used, 0);
    //     return res;
    // }
    // void backtracking(vector<int> &nums, vector<bool>& used, int pos)
    // {
    //     res.push_back(ve);
    //     if (pos >= nums.size())
    //     {
    //         return;
    //     }
    //     for (int i = pos; i < nums.size(); ++i)
    //     {
    //         if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
    //         {
    //             continue;
    //         }
    //         ve.push_back(nums[i]);
    //         used[i] = true;
    //         backtracking(nums, used, i + 1);
    //         used[i] = false;
    //         ve.pop_back();
    //     }
    // }

    //使用set来去重
    vector<vector<int>> res;
    vector<int> ve;
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    { //注意回溯过程中要进行树层去重
        sort(nums.begin(), nums.end());//去重需要排序
        backtracking(nums, 0);
        return res;
    }
    void backtracking(vector<int> &nums, int pos)
    {
        res.push_back(ve);
        unordered_set<int> uset;
        //很奇怪为什么set放在这个位置呢？
        //细细体会！！！
        if (pos >= nums.size())
        {
            return;
        }
        for (int i = pos; i < nums.size(); ++i)
        {
            if (uset.find(nums[i])!=uset.end())
            {
                continue;
            }
            uset.insert(nums[i]);
            ve.push_back(nums[i]);
            backtracking(nums, i + 1);
            ve.pop_back();
        }
    }

    // vector<vector<int>> res;
    // vector<int> ve;
    // vector<vector<int>> subsetsWithDup(vector<int> &nums)
    // {                                   //注意回溯过程中要进行树层去重
    //     sort(nums.begin(), nums.end()); //去重需要排序
    //     backtracking(nums, 0);
    //     return res;
    // }
    // void backtracking(vector<int> &nums, int pos)
    // {
    //     res.push_back(ve);
    //     for (int i = pos; i < nums.size(); ++i)
    //     {
    //         if (i>pos&&nums[i]==nums[i-1])
    //         {
    //             continue;
    //         }
    //         ve.push_back(nums[i]);
    //         backtracking(nums, i + 1);
    //         ve.pop_back();
    //     }
    // }
};
// @lc code=end
