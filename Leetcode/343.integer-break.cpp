// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem343.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution
{
    /*
dp[i]表示的是：拆分数字i可以得到的最大乘积为dp[i]
dp[i]的获取可以通过两种方式：
j*(i-j):其中j是从1遍历到j
j*dp[i-j],这就相当于继续拆分（i-j）
*/
public:
    // int integerBreak(int n)
    // {
    //     vector<int> dp(n + 1);
    //     dp[2] = 1;
    //     for (int i = 3; i <= n; ++i)
    //     {
    //         for (int j=1;j<i-1;++j){
    //             dp[i] = max(dp[i],max((i-j)*j,dp[i-j]*j));
    //         }
    //     }
    //     return dp[n];
    // }

    /*
    本题也可以使用贪心算法来解题
    一个结论：每次拆分成n个3，如果剩下是4，则保留4，然后相乘。
    这个结论可以通过数学证明出来
    */
    int integerBreak(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n == 4)
            return 4;
        int res = 1;
        while (n > 4)
        {
            res *= 3;
            n -= 3;
        }
        res *= n;
        return res;
    }
};
// @lc code=end
