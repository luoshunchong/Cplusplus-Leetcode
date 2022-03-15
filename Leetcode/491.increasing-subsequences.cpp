// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem491.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> ve;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
    void backtracking(vector<int>& nums, int pos){
        if(ve.size()>=2){
            res.push_back(ve);
        }
        unordered_set<int> uset;
        for(int i=pos;i<nums.size();++i){
            if ((!ve.empty() && nums[i] < ve.back()) || uset.find(nums[i])!=uset.end())
            {
                continue;
            }
            uset.insert(nums[i]);
            ve.push_back(nums[i]);
            backtracking(nums, i+1);
            ve.pop_back();
        }
    }
};
// @lc code=end

