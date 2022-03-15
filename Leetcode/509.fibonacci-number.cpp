/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    // int fib(int n) {//正常的方法
    //     if(n<=1) return n;
    //     vector<int> dp(n+1);
    //     dp[0] = 0;
    //     dp[1] = 1;
    //     for(int i=2;i<=n;++i){
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }

    // int fib(int n)
    // { //优化的方法，我们只需要维护两个数值就可以了
    //     if (n <= 1)
    //         return n;
    //     int dp[2];
    //     dp[0] = 0;
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; ++i)
    //     {
    //         int sum = dp[0] + dp[1];
    //         dp[0] = dp[1];
    //         dp[1] = sum;
    //     }
    //     return dp[1];
    // }

    int fib(int n)
    { //递归的方法
        if (n <= 1)
            return n;
        return fib(n-1) + fib(n-2);
    }
};
// @lc code=end

