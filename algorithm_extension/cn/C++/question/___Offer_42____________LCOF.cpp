// @algorithm @lc id=100304 lang=cpp 
// @title lian-xu-zi-shu-zu-de-zui-da-he-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
//@test([-2,1,-3,4,-1,2,1,-5,4])=6
//@test([-2])=-2
//@test([-1,2,4,-7,5,8])=13
//@test([-2,-1])=-1
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //动态规划
        int res = nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};