// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem746.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    // int minCostClimbingStairs(vector<int> &cost)
    // {//常规版本
    //     vector<int> dp(cost.size());
    //     dp[0] = cost[0];
    //     dp[1] = cost[1];
    //     for (int i = 2; i < cost.size(); ++i)
    //     {
    //         dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    //     }
    //     return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    // }

    int minCostClimbingStairs(vector<int> &cost)
    { //优化版本
        int dp0 = cost[0];
        int dp1 = cost[1];
        for (int i = 2; i < cost.size(); ++i)
        {
            int dpi = min(dp0, dp1) + cost[i];
            dp0 = dp1;
            dp1 = dpi;
        }
        return min(dp0,dp1);
    }
};
// @lc code=end
