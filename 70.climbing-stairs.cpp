/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    // int climbStairs(int n)
    // {//常规方法
    //     if (n <= 1)
    //         return n;
    //     vector<int> dp(n + 1);
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for (int i = 3; i <= n; i++)
    //     {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }

    int climbStairs(int n)
    { //优化的方法
        if (n <= 1)
            return n;
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            int sum = dp[1] +dp[2];
            dp[1] = dp[2];
            dp[2] = sum; 
        }
        return dp[2];
    }
};
// @lc code=end
